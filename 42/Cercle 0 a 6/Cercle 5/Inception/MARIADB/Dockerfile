# rappel des consignes : MARIADB sans NGINX

FROM debian:bookworm
# bookworm est la version 12.2 de debian c'est la derniere version stable en oct 2023

# update des paquets (eventuellement) et install de nginx
# RUN apt update && apt upgrade && apt install mariadb-server  mariadb-client -y && rm -rf /var/lib/apt/lists/*
# # on ecrase le fichier de conf "de base" par celui prevu et aui est dans le dossier config
# COPY config/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# # je lance mysql (rappel mariaDB et mysql est la meme chose sauf que mysql est devenu payant)

# RUN rm -rf /var/lib/apt/lists/*
# # purge and re-create /var/lib/mysql with appropriate ownership
# RUN mkdir -p /var/run/mysqld
# RUN chown -R mysql:mysql /var/run/mysqld
# # ensure that /var/run/mysqld (used for socket and lock files) is writable regardless of the UID our mysqld instance ends up having at runtime
# RUN chmod 777 /var/run/mysqld

# EXPOSE 3306

# COPY ./tools/create_db.sh /
# RUN chmod 777 create_db.sh
# # COPY ./conf/wordpress.sql /usr/local/bin/
# ENTRYPOINT ["/bin/bash ./create_db.sh"]

# CMD ["mysqld", "--bind-address=0.0.0.0"]