# User documentation

This guide is for the person who runs and uses the site, no Docker knowledge
required.

## Start and stop the stack

All commands are run from the root of the repository.

```bash
make          # first start: installs prerequisites if needed, then builds and starts everything
make down     # stop the site (data is kept)
make up       # start it again
make re       # full rebuild from scratch (wipes all data!)
```

The first start can take a few minutes (images are built and WordPress is
installed automatically). Afterwards, check that the three services are up:

```bash
docker compose -f srcs/docker-compose.yml ps
```

You should see `nginx`, `wordpress` and `mariadb` with status `Up`.

## Access the website

- Website: <https://sipyeon.42.fr>
- Administration panel: <https://sipyeon.42.fr/wp-admin>

The site is only reachable over HTTPS (port 443). Because the certificate is
self-signed, the browser shows a security warning on first visit — choose
"Advanced" → "Proceed". Plain `http://` access is refused by design.

## Accounts and credentials

Credentials are generated on first setup and stored locally (they are not in
git):

- `srcs/secrets/wordpress.env` — WordPress administrator (`WP_ADMIN_USER` /
  `WP_ADMIN_PASSWORD`) and a regular user (`WP_USER` / `WP_PASSWORD`).
- `srcs/secrets/mariadb.env` and `srcs/secrets/db-info.env` — database root
  and application passwords.

To change a WordPress password, log into the admin panel and use
Users → Profile. To regenerate all credentials from scratch, run `make clean`
(this also deletes the volumes), delete `srcs/.env` and the three files in
`srcs/secrets/`, then run `make` again — the site is recreated, so content is
lost.

## Basic checks

- Site up? `curl -k -o /dev/null -w "%{http_code}\n" https://sipyeon.42.fr`
  should print `200`.
- Containers up? `docker ps` should list `nginx`, `wordpress`, `mariadb`.
- Logs of a service: `docker logs nginx` (or `wordpress`, `mariadb`).
- Data on disk: `docker volume ls` — the `srcs_wordpress` and `srcs_mariadb`
  volumes hold the site files and the database, and survive restarts.

If a container crashed, Docker restarts it automatically. If the site stays
unreachable, run `make down && make up`.
