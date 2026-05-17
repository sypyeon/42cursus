COMPOSE_FILE := srcs/docker-compose.yml
COMPOSE := docker compose -f $(COMPOSE_FILE)
VOLUME_PATH := $(HOME)/data

.PHONY: all build up down clean re

all: build up

build:
	mkdir -p $(VOLUME_PATH)/wordpress $(VOLUME_PATH)/mariadb
	$(COMPOSE) build --no-cache

up:
	$(COMPOSE) up -d

down:
	$(COMPOSE) down

clean:
	docker system prune -a --volumes -f
	sudo rm -rf $(VOLUME_PATH)/*

re: down clean all