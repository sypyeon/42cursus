*This project has been created as part of the 42 curriculum by sipyeon.*

# Inception

## Description

Inception is a system administration project. The goal is to build a small web
infrastructure entirely with Docker, writing every Dockerfile by hand instead
of pulling ready-made images. The stack is composed of three services, each
running in its own container and connected through a dedicated Docker network:

- **NGINX** — the single entry point of the infrastructure. It only listens on
  port 443 (HTTPS) with TLSv1.3 and a self-signed certificate generated at
  container startup. Static files are served directly; PHP requests are
  forwarded to the WordPress container over FastCGI.
- **WordPress + PHP-FPM** — runs the WordPress application with php-fpm only
  (no web server inside). On first start, the site is downloaded, configured
  and installed automatically with wp-cli, including an administrator and a
  regular user.
- **MariaDB** — the database. On first start it initializes its data
  directory, sets the root password and creates the WordPress database and a
  dedicated user.

Data is persisted through two Docker named volumes, `mariadb` and
`wordpress`, managed entirely by Docker, so the site and its database survive
container rebuilds. Credentials are never committed
to git: they live in local env files generated from the `*.env.example`
templates by `scripts/setup.sh`, which fills in random secrets.

## Project description

### Use of Docker

Docker is used to split one web stack into three isolated processes that are
built, started and torn down reproducibly. Every image is built from a
Dockerfile in this repository — nothing is pulled ready-made from Docker Hub
except the two base images allowed by the subject (`alpine:3.23.5` and
`debian:12`, both the penultimate stable release of their distribution).

Each container runs exactly one service as PID 1: the entrypoint scripts do
their setup work and then `exec` the daemon in the foreground
(`nginx -g 'daemon off;'`, `php-fpm83 -F`, `mysqld --console`). Nothing is
daemonised and there is no `tail -f`/`sleep infinity` keep-alive, so when a
service dies the container dies with it and the `restart` policy brings it
back — which is the behaviour the subject asks for.

### Sources included in the project

| Path | Role |
|---|---|
| `Makefile` | Entry point; runs setup then `docker compose up --build -d` |
| `scripts/setup.sh` | One-time host setup: Docker, `/etc/hosts`, generated env files |
| `srcs/docker-compose.yml` | 3 services, 1 bridge network, 2 named volumes |
| `srcs/.env` | `DOMAIN_NAME` (git-ignored; generated from `.env.example`) |
| `srcs/secrets/*.env` | Credentials (git-ignored; generated from `*.env.example`) |
| `srcs/requirements/nginx/` | Dockerfile, `template.conf`, entrypoint |
| `srcs/requirements/wordpress/` | Dockerfile, `template.php`, entrypoint |
| `srcs/requirements/mariadb/` | Dockerfile, `init.sql`, entrypoint |

### Main design choices

- **Alpine for NGINX and WordPress, Debian for MariaDB.** Alpine keeps the
  two front-end images small (25 MB and 73 MB). MariaDB is built on Debian
  because `mariadb-server` there ships a predictable `mysql_install_db` and
  init-file behaviour, which keeps the entrypoint simple.
- **Configuration is templated at runtime, not baked into the image.**
  `envsubst` renders `template.conf`, `template.php` and `init.sql` when the
  container starts, so no credential or domain is ever written into an image
  layer. `envsubst` is always called with an explicit variable list so that
  NGINX's `$uri`/`$args` and PHP's `$table_prefix` survive substitution.
- **Unattended WordPress install with wp-cli.** The entrypoint waits for
  MariaDB's port, then downloads, configures and installs WordPress and
  creates the two required users — only on first run, so restarts are
  idempotent.
- **Self-signed certificate generated at container start**, so no key
  material is stored in the repository or in an image.
- **Credentials are generated, never authored.** `scripts/setup.sh` fills the
  `__GENERATE__` placeholders in the templates with random 32-character
  values. The resulting files are git-ignored.

### Virtual Machines vs Docker

A virtual machine emulates hardware and boots a complete guest kernel and
userland on top of a hypervisor. A container is just a group of processes on
the *host* kernel, isolated by namespaces (PID, network, mount, user) and
limited by cgroups.

The practical consequences: a VM costs GBs of disk and tens of seconds to
boot, while these three images total ~600 MB and start in about a second. A
VM gives stronger isolation because the guest kernel boundary is a real
boundary — a container escape is a host compromise, a VM escape needs a
hypervisor bug. A VM can run a different kernel or OS family; a container
cannot, which is why these Linux images cannot run on a Windows kernel
without a Linux VM underneath.

They are complementary rather than competing, and this project shows why:
the whole stack is containerised, but it is required to run inside a VM, so
the VM provides the isolated machine and Docker provides the per-service
isolation inside it.

### Secrets vs Environment Variables

Environment variables are the simple mechanism: values are handed to the
container at start and read from the process environment. They are
convenient, but they leak easily — `docker inspect` prints them, they are
visible in `/proc/<pid>/environ` to anything in the container, they are
inherited by every child process, and they routinely end up in crash dumps
and logs.

Docker secrets are files instead. The value is mounted read-only into the
container (as a `tmpfs` file under `/run/secrets/` in Swarm), it is not part
of the environment, `docker inspect` does not reveal its content, and access
can be granted per service. In Compose without Swarm, secrets are backed by a
local file but still mounted as a file rather than exported to the process
environment.

This project uses `env_file` rather than Docker secrets, which the subject
permits (secrets are "strongly recommended", environment variables are
mandatory). The risk that actually matters for the subject — credentials
committed to git — is handled a different way: the real `.env` files do not
exist in the repository at all. Only `*.example` templates with
`__GENERATE__` placeholders are tracked, and `scripts/setup.sh` generates
random values locally on first run. Moving to Docker secrets would be the
next hardening step: it would keep the passwords out of the container
environment as well as out of git.

### Docker Network vs Host Network

A user-defined bridge network (`inception`) gives the containers their own
network namespace and their own subnet. Two things follow. First, Docker's
embedded DNS resolves service names, which is why `fastcgi_pass wordpress:9000`
and `WORDPRESS_DB_HOST=mariadb` work without hardcoding any IP. Second, a
port is only reachable from outside if it is explicitly published — so
php-fpm on 9000 and MariaDB on 3306 stay internal, and 443 on the NGINX
container is the single entry point the subject requires.

`network_mode: host` removes that namespace: the container shares the host's
network stack directly. It is marginally faster (no NAT, no veth pair) but it
destroys the isolation — every container port becomes a host port, service
names no longer resolve, and two containers cannot both listen on 3306. It is
forbidden by the subject, and this design is the reason why: with host
networking the database would be exposed on the VM's interface and NGINX
would no longer be the only way in.

### Docker Volumes vs Bind Mounts

A bind mount maps an arbitrary host path into a container. The container
inherits whatever ownership and permissions already exist on that path, the
path must exist beforehand, and the setup is tied to one host's filesystem
layout.

A named volume is managed by Docker: it is referenced by name, it appears in
`docker volume ls`, Docker creates it if missing and owns its storage, its
lifecycle is independent of any container, and it is portable across hosts
and drivers.

The subject requires named volumes and explicitly forbids bind mounts for the
two persistent storages, so both are declared with no `driver_opts` at all:

```yaml
volumes:
  mariadb:
  wordpress:
```

Docker allocates the backing store itself under `/var/lib/docker/volumes/`,
and `docker volume inspect srcs_mariadb` shows a plain `local` volume with no
`o: bind` option. The database files and the WordPress tree therefore survive
`docker compose down`, container recreation and host reboots, and are removed
only by an explicit `docker compose down -v` (`make clean`).

An earlier version of this project pinned the volumes to `~/data` with
`driver_opts: {type: none, o: bind, device: ...}`. That is a bind mount
wearing a named volume's name, which the subject forbids, so it was removed.

## Instructions

Requirements: Linux with Docker and the Docker Compose plugin (the setup
script can install both), and sudo rights to add the domain to `/etc/hosts`.

```bash
git clone <repository> inception && cd inception
make          # setup (docker, hosts entry, env files) + build + start
```

Then open <https://sipyeon.42.fr> in a browser and accept the self-signed
certificate warning. The admin panel is at <https://sipyeon.42.fr/wp-admin>;
credentials are in `srcs/secrets/wordpress.env`.

Other targets:

```bash
make down     # stop the stack
make up       # rebuild and start
make clean    # stop and remove this project's containers, images and volumes
make re       # clean + up
```

See [USER_DOC.md](USER_DOC.md) for day-to-day usage and
[DEV_DOC.md](DEV_DOC.md) for developer documentation.

## Resources

- [Docker documentation](https://docs.docker.com/) — Dockerfile reference,
  networking and volumes.
- [Docker Compose documentation](https://docs.docker.com/compose/)
- [NGINX documentation](https://nginx.org/en/docs/) — SSL/TLS and FastCGI
  configuration.
- [WP-CLI handbook](https://make.wordpress.org/cli/handbook/) — unattended
  WordPress installation.
- [MariaDB knowledge base](https://mariadb.com/kb/en/) — initialization and
  user management.

### How AI was used

AI (Claude) was used as a review and documentation assistant: auditing the
configuration against the subject's requirements (TLS settings, exposed ports,
PID 1 behaviour, volume paths), refactoring credential handling so that no
secrets are tracked by git (env templates plus a setup script that generates
random passwords), and helping write this documentation. The infrastructure
itself — Dockerfiles, service configuration and startup scripts — was written
and is understood by the author; AI output was reviewed and tested before
being kept.
