# rappel des consignes : MARIADB sans NGINX

FROM debian:bookworm
# bookworm est la version 12.2 de debian c'est la derniere version stable en oct 2023

RUN echo "\e[33m ~~~~~ MARIADB DEBUT D'INSTALLATION ~~~~~"
# update des paquets (eventuellement) et install de nginx
RUN apt update -y && apt upgrade -y && apt install mariadb-server -y && rm -rf /var/lib/apt/lists/*
# on ecrase le fichier de conf "de base" par celui prevu et aui est dans le dossier config
COPY config/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/config.sh ./
EXPOSE 3306
ENTRYPOINT ["/bin/sh", "-c", "./config.sh"]
RUN echo "~~~~~ MARIADB FIN D'INSTALLATION ~~~~~ \e[0m"
