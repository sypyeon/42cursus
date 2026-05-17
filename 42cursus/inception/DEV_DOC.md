# Developer Documentation

Setup from scratch:

1. Install Docker and Docker Compose.
2. Copy secret samples to concrete files and fill values:

```sh
cd srcs
cp secrets/wordpress.env.sample secrets/wordpress.env
cp secrets/mariadb.env.sample secrets/mariadb.env
cp secrets/db-info.env.sample secrets/db-info.env
# edit the files and set secure passwords and keys
```

3. Generate TLS certs for your `DOMAIN_NAME` declared in `srcs/.env`:

```sh
sh srcs/secrets/generate_certs.sh
```

Build and launch using the Makefile or docker compose directly:

```sh
cd srcs
# using docker compose
docker compose up --build -d
# or use Makefile targets if provided
make build
make up
```

Managing containers:
- `docker compose ps`
- `docker compose logs -f <service>`
- `docker compose down` to stop and remove containers

Persistent data locations:
- The `docker-compose.yml` uses named volumes `wordpress` and `mariadb` which are bound to host under `/home/sipyeon/data/wordpress` and `/home/sipyeon/data/mariadb` (update `docker-compose.yml` if you need a different location). Ensure the host path exists and is writable by Docker.
