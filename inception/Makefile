COMPOSE_FILE = srcs/docker-compose.yml
DATA_PATH = $(HOME)/data
COMPOSE = docker compose -f $(COMPOSE_FILE)

all: setup up

setup:
	@which docker > /dev/null 2>&1 && docker compose version > /dev/null 2>&1 \
		&& grep -q "sipyeon.42.fr" /etc/hosts \
		&& { ! docker info 2>/dev/null | grep -q rootless \
			|| test "$$(sysctl -n net.ipv4.ip_unprivileged_port_start)" -le 443; } \
		&& test -f srcs/.env \
		&& test -f srcs/secrets/mariadb.env \
		&& test -f srcs/secrets/db-info.env \
		&& test -f srcs/secrets/wordpress.env \
		|| bash scripts/setup.sh

up:
	mkdir -p $(DATA_PATH)/mariadb $(DATA_PATH)/wordpress
	docker compose -f $(COMPOSE_FILE) up --build -d
	$(COMPOSE) up --build -d

down:
	$(COMPOSE) down

clean:
	docker system prune -a --volumes -f
	rm -rf $(DATA_PATH)
	$(COMPOSE) down -v --rmi local

re: clean up

.PHONY: all setup up down clean re
