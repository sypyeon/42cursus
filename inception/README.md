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

Data is persisted on the host through two bind-mounted volumes
(`~/data/mariadb` and `~/data/wordpress`), so the site and its database
survive container rebuilds. Credentials are never committed to git: they live
in local env files generated from the `*.env.example` templates by
`scripts/setup.sh`, which fills in random secrets.

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
make clean    # stop, remove images/volumes and wipe ~/data
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
