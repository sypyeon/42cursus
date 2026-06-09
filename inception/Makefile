COMPOSE_FILE = srcs/docker-compose.yml
DATA_PATH = $(HOME)/data

all: up

up:
	mkdir -p $(DATA_PATH)/mariadb $(DATA_PATH)/wordpress
	docker-compose -f $(COMPOSE_FILE) up --build -d

down:
	docker-compose -f $(COMPOSE_FILE) down

clean: down
	docker system prune -a --volumes -f
	rm -rf $(DATA_PATH)

re: clean up

.PHONY: all up down clean re