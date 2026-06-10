COMPOSE_FILE = srcs/docker-compose.yml
DATA_PATH = $(HOME)/data

all: setup up

setup:
	@which docker > /dev/null 2>&1 && docker compose version > /dev/null 2>&1 \
		&& grep -q "sipyeon.42.fr" /etc/hosts \
		|| bash scripts/setup.sh

up:
	mkdir -p $(DATA_PATH)/mariadb $(DATA_PATH)/wordpress
	docker compose -f $(COMPOSE_FILE) up --build -d

down:
	docker compose -f $(COMPOSE_FILE) down

clean: down
	docker system prune -a --volumes -f
	rm -rf $(DATA_PATH)

re: clean up

.PHONY: all setup up down clean re
