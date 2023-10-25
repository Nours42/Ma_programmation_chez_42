# rappel des consignes : NGINX avec TLS v1.2

FROM debian:buster

RUN apt update && apt upgrade && apt install nginx -y
RUN apt install vim -y
RUN apt install curl -y
RUN mkdir -p /etc/nginx/ssl
RUN apt install libssl-dev -y
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login"
RUN mkdir -p /var/run/nginx
COPY config/nginx.conf /etc/nginx/nginx.conf

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