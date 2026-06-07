*This project has been created as part of the 42 curriculum by sipyeon.*

**Description**
- Inception is a small Docker Compose infrastructure for a TLS-protected WordPress site using NGINX, WordPress (PHP-FPM), and MariaDB.

**Instructions**
- Copy sample secret files from `srcs/secrets/*.sample` to files without `.sample` and fill secure values.
- Generate TLS certs (or provide valid ones) and place them in `srcs/secrets`.
- From `srcs` run `make build` or `docker compose up --build` (see `DEV_DOC.md`).

**Resources**
- Docker docs: https://docs.docker.com
- WordPress docs: https://wordpress.org/support/
- NGINX TLS: https://nginx.org/en/docs/http/configuring_https_servers.html

**AI usage**
- I used AI to generate project scaffolding and documentation templates only.

**Project description**
- Main design choices: Alpine base images, one service per container, environment-driven configuration.
- Comparisons:
  - Virtual Machines vs Docker: Docker provides lightweight OS-level isolation compared to full VMs; faster startup and lower overhead.
  - Secrets vs Environment Variables: Use Docker secrets for sensitive data in production; `.env` and env files are convenient for development but should not contain raw secrets in the repo.
  - Docker Network vs Host Network: Use user-defined bridge networks (recommended) to isolate and control container communication; `host` exposes host interfaces and is less secure.
  - Docker Volumes vs Bind Mounts: Volumes are managed by Docker and work well for persistent data; bind mounts are useful for development when you need host file sync.
