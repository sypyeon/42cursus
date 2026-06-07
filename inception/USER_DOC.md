# User Documentation

- Services provided: `nginx` (TLS reverse proxy), `wordpress` (PHP-FPM + WP site), `mariadb` (database).

Start the project:

```sh
cd srcs
# copy samples to real env files and fill in secrets
cp secrets/wordpress.env.sample secrets/wordpress.env
cp secrets/mariadb.env.sample secrets/mariadb.env
cp secrets/db-info.env.sample secrets/db-info.env
# generate certs (optional)
sh secrets/generate_certs.sh
# start services
docker compose up --build -d
```

Stop the project:

```sh
cd srcs
docker compose down
```

Access the website:
- Visit `https://<your-domain>` (e.g., https://sipyeon.42.fr) — `nginx` listens on port 443 only.

Administration panel:
- WordPress admin: `https://<your-domain>/wp-admin` using credentials from `srcs/secrets/wordpress.env`.

Credentials location:
- Secrets are stored locally in `srcs/secrets` and should be kept out of git. Use the sample files to create real ones.

Check services:
- `docker compose ps` in `srcs` shows running containers.
- `docker logs <container>` to inspect individual containers.
