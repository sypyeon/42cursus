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

# /etc/hosts
DOMAIN="sipyeon.42.fr"
if ! grep -q "$DOMAIN" /etc/hosts; then
    echo "[+] Adding $DOMAIN to /etc/hosts..."
    echo "127.0.0.1 $DOMAIN" | sudo tee -a /etc/hosts > /dev/null
else
    echo "[*] $DOMAIN already in /etc/hosts"
fi

echo "=== Setup complete ==="
