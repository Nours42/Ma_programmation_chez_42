# rappel des consignes : WordPress avec php-fpm configuré

FROM debian:bookworm
# bookworm est la version 12.2 de debian c'est la derniere version stable en oct 2023
RUN echo "\e[33m ~~~~~ WORDPRESS DEBUT D'INSTALLATION ~~~~~"
# update des paquets (eventuellement) et install de php 7.3 et des dependances necessaires a WordPress
RUN apt update -y && apt upgrade -y 
RUN apt install vim -y
RUN apt install 	curl -y
RUN apt install 	wget -y
RUN apt install 	procps -y
RUN apt install 	mime-support -y
RUN apt install 	php8.2 -y
RUN apt install 	php8.2-cli -y
RUN apt install 	php8.2-bz2 -y
RUN apt install 	php8.2-curl -y
RUN apt install 	php8.2-mbstring -y
RUN apt install 	php8.2-intl -y
RUN apt install 	php8.2-fpm -y
RUN apt install 	mariadb-client -y
RUN rm -rf /var/lib/apt/lists/*
# je telecharge WP-CLI un logiciel permettant la configuration de wordpress en ligne de commandes
# je lui donne des droits et le place au bon endroit
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod 777 wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

# je recupere WordPress dans sa version 6.3.2 (la derniere)
RUN	mkdir -p /var/www/wordpress \
	&& cd /var/www/wordpress \
	&& wp core download "https://fr.wordpress.org/wordpress-6.3.2-fr_FR.tar.gz" --allow-root \
	&& chown -R root:root /var/www/wordpress
RUN	mkdir -p /run/php
COPY ["./config/php.conf", "./etc/php/7.3/fpm/pool.d/www.conf"]
COPY ["./tools/config.sh", "./"]
RUN chmod 777 config.sh
EXPOSE 9000
ENTRYPOINT ["/bin/sh", "-c", "./config.sh"]
CMD ["/usr/sbin/php-fpm8.2", "--nodaemonize"]