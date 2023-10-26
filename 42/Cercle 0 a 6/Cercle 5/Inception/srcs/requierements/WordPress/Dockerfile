# rappel des consignes : WordPress avec php-fpm configuré

FROM debian:bookworm
# bookworm est la version 12.2 de debian c'est la derniere version stable en oct 2023
RUN echo "\e[33m ~~~~~ WORDPRESS DEBUT D'INSTALLATION ~~~~~"
# update des paquets (eventuellement) et install de php 7.3 et des dependances necessaires a WordPress
RUN apt update -y && apt upgrade -y && apt install vim \
	curl \
	wget \
	procps \
	mime-support \
	php-common \
	php-mysql \
	php7.3-cli \
	php7.3-common \
	php7.3-json \
	php7.3-opcache \
	php7.3-readline \
	php7.3-mysql \
	php-fpm \
	mariadb-client \
	&& rm -rf /var/lib/apt/lists/*
# je telecharge WP-CLI un logiciel permettant la configuration de wordpress en ligne de commandes
# je lui donne des droits et le place au bon endroit
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

# je recupere WordPress dans sa version 6.3.2 (la derniere)
RUN	mkdir -p /var/www/wordpress \
	&& cd /var/www/wordpress \
	&& wp core download "https://fr.wordpress.org/wordpress-6.3.2-fr_FR.tar.gz" --allow-root \
	&& chown -R root:root /var/www/wordpress
RUN	mkdir -p /run/php
COPY ["./config/php.conf", "./etc/php/7.3/fpm/pool.d/www.conf"]
COPY ["./tools/auto_config.sh", "./"]
#ADD
#WORKDIR
EXPOSE 9000
#STOPSIGNAL SIGQUIT
#USER
#ONBUILD
#CMD ["ping", "localhost"]
ENTRYPOINT ["/bin/sh", "-c", "./config.sh"]