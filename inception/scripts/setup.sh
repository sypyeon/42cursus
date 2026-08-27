#!/bin/bash
set -e

echo "=== Inception Setup ==="

# Docker
if ! which docker > /dev/null 2>&1; then
    echo "[+] Installing Docker..."
    curl -fsSL https://get.docker.com | sh
    sudo usermod -aG docker "$USER"
    echo "[+] Docker installed. You may need to re-login for group changes to take effect."
else
    echo "[*] Docker already installed: $(docker --version)"
fi

# docker-compose v2 plugin
if ! docker compose version > /dev/null 2>&1; then
    echo "[+] Installing docker-compose-plugin..."
    sudo apt-get update -qq
    sudo apt-get install -y docker-compose-plugin
else
    echo "[*] docker compose already installed: $(docker compose version)"
fi

# env files (copy templates, fill __GENERATE__ with random secrets)
gen_secret() {
    tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c 32
}

for f in srcs/.env srcs/secrets/mariadb.env srcs/secrets/db-info.env srcs/secrets/wordpress.env; do
    if [ ! -f "$f" ]; then
        cp "$f.example" "$f"
        while grep -q "__GENERATE__" "$f"; do
            sed -i "0,/__GENERATE__/s//$(gen_secret)/" "$f"
        done
        echo "[+] Created $f from template (random secrets generated)"
    else
        echo "[*] $f already exists"
    fi
done

# Privileged port for rootless Docker.
# Rootless dockerd cannot publish 443 unless the host lowers this sysctl.
# Written to /etc/sysctl.d so it survives the reboot the evaluation performs.
PORT_START=$(sysctl -n net.ipv4.ip_unprivileged_port_start)
if docker info 2>/dev/null | grep -q rootless && [ "$PORT_START" -gt 443 ]; then
    echo "[+] Allowing unprivileged bind on port 443..."
    echo "net.ipv4.ip_unprivileged_port_start=443" \
        | sudo tee /etc/sysctl.d/99-inception.conf > /dev/null
    sudo sysctl -q -w net.ipv4.ip_unprivileged_port_start=443
else
    echo "[*] Unprivileged port start already <= 443 ($PORT_START)"
fi

# /etc/hosts
DOMAIN="sipyeon.42.fr"
if ! grep -q "$DOMAIN" /etc/hosts; then
    echo "[+] Adding $DOMAIN to /etc/hosts..."
    echo "127.0.0.1 $DOMAIN" | sudo tee -a /etc/hosts > /dev/null
else
    echo "[*] $DOMAIN already in /etc/hosts"
fi

echo "=== Setup complete ==="
