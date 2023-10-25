# rappel des consignes : NGINX avec TLS v1.2

FROM debian:bookworm
# bookworm est la version 12.2 de debian c'est la derniere version stable en oct 2023

# update des paquets (eventuellement) et install de nginx
RUN apt update && apt upgrade && apt install nginx -y
# installatation de vim et de curl (au cas ou)
RUN apt install vim -y
RUN apt install curl -y
# creation d'un dossier pour le ssl
RUN mkdir -p /etc/nginx/ssl
# installation de openssl (libssl-dev ici)
RUN apt install libssl-dev -y
# parametrage dus ssl pour qu'il n'y ait pas de mdp
# et qu'il soit parametrer pour fonctionner tel que le demande le sujet
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login"
# lancement de nginx et config de qq param pour WordPress
RUN mkdir -p /var/run/nginx
COPY config/nginx.conf /etc/nginx/nginx.conf
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html
CMD [ "nginx", "-g", "daemon off;" ]

# RUN apt update && apt upgrade && apk add \
# 			openssl			\
# 			nginx			\
# 			curl			\
# 			vim				\
# 			sudo

# RUN	rm -f /etc/nginx/nginx.conf

# COPY ./config/nginx.conf /etc/nginx/nginx.conf
# COPY scripts/setup_nginx.sh /setup_nginx.sh

# RUN chmod -R +x /setup_nginx.sh

# EXPOSE	443

# ENTRYPOINT [ "sh", "setup_nginx.sh" ]