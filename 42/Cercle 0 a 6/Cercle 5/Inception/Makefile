all: data db wp up

up:
	docker-compose -f ./srcs/docker-compose.yml up -d
data:
	mkdir -p /home/sdestann/data
db:
	mkdir -p /home/sdestann/data/db
wp:
	mkdir -p /home/sdestann/data/wp

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
