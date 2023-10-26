all: data db wp up

up:
	docker-compose -f ./srcs/docker-compose.yml up -d
data:
	mkdir /home/sdestann/data
db:
	mkdir /home/sdestann/data/db
wp:
	mkdir /home/sdestann/data/wp

down:
	docker-compose -f ./srcs/docker-compose.yml down

.PHONY: up data db wp down
