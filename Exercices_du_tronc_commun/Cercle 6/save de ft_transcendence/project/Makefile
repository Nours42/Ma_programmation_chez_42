all: up

up:
	docker-compose -f ./srcs/docker-compose.yml up -d

ps:
	cd ./srcs/ && docker-compose ps -a

down:
	docker-compose -f ./srcs/docker-compose.yml down
stop:
	cd ./srcs/ && docker-compose stop 

clean:
	cd ./srcs/ && docker-compose stop 
	cd ./srcs/ && docker-compose down -v

.PHONY: up data db wp down
