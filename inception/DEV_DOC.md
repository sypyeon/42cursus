# Developer documentation

## Prerequisites

- Linux host (the project is meant to run inside a VM).
- Docker Engine and the Docker Compose v2 plugin. If either is missing,
  `make` runs `scripts/setup.sh`, which installs them via the official
  convenience script / apt.
- `sudo` rights (needed once, to add `sipyeon.42.fr` to `/etc/hosts`).

## Project layout

```
Makefile                 entry point (wraps docker compose)
scripts/setup.sh         one-time host setup: docker, /etc/hosts, env files
srcs/
  docker-compose.yml     orchestration: 3 services, 1 network, 2 volumes
  .env(.example)         DOMAIN_NAME
  secrets/*.env(.example) credentials (real files are git-ignored)
  requirements/
    nginx/               Dockerfile, nginx config template, entrypoint
    wordpress/           Dockerfile, wp-config template, entrypoint
    mariadb/             Dockerfile, init.sql template, entrypoint
```

Each service has exactly one Dockerfile. Images are built from the
penultimate stable base versions (`alpine:3.23.5`, `debian:12`) and are named
after their service (`nginx`, `wordpress`, `mariadb`).

## Setup and secrets

`scripts/setup.sh` creates `srcs/.env` and `srcs/secrets/*.env` from their
`.example` templates the first time, replacing every `__GENERATE__`
placeholder with a random 32-character secret. Real env files are listed in
`.gitignore` and must never be committed. Compose injects them with
`env_file:`; the entrypoints render config files from templates with
`envsubst` at container startup.

## Makefile targets

```bash
make          # setup + up
make setup    # checks docker/compose/hosts/env files, runs scripts/setup.sh if needed
make up       # mkdir ~/data/{mariadb,wordpress}; docker compose up --build -d
make down     # docker compose down
make clean    # down + docker system prune -a --volumes + rm -rf ~/data
make re       # clean + up
```

## Useful docker compose commands

Run from the repository root with `-f srcs/docker-compose.yml`:

```bash
docker compose -f srcs/docker-compose.yml ps            # container status
docker compose -f srcs/docker-compose.yml logs -f nginx # follow logs
docker compose -f srcs/docker-compose.yml build nginx   # rebuild one service
docker compose -f srcs/docker-compose.yml up -d --build # rebuild + restart stack
docker exec -it mariadb mysql -uroot -p                 # database shell
docker exec -it wordpress sh                            # shell in a container
```

## Architecture notes

- **Network**: all three containers share the `inception` bridge network.
  Containers address each other by service name via Docker's embedded DNS
  (`fastcgi_pass wordpress:9000`, `WORDPRESS_DB_HOST=mariadb`).
- **Entry point**: only nginx publishes a port (`443:443`), TLSv1.3 with a
  self-signed certificate generated in its entrypoint. php-fpm (9000) and
  MariaDB (3306) are reachable only inside the Docker network.
- **PID 1**: every entrypoint script ends with `exec` on the real daemon run
  in foreground (`nginx -g 'daemon off;'`, `php-fpm83 -F`,
  `mysqld --console`), so a crashed service kills its container and the
  `restart: unless-stopped` policy brings it back.
- **Bootstrap**: WordPress's entrypoint waits for MariaDB's port, then uses
  wp-cli to download/configure/install the site and create the two users —
  only on first run (idempotent).

## Data persistence

Two named volumes are bind-mounted to the host:

- `~/data/mariadb` ↔ `/var/lib/mysql` (database files)
- `~/data/wordpress` ↔ `/var/www/html` (WordPress files, shared with nginx
  so it can serve static assets directly)

`make down` / reboots keep all data; recreating containers reuses it. Only
`make clean` / `make re` wipe `~/data`. To reset a single service's state,
stop the stack and remove the matching directory before `make up`.
