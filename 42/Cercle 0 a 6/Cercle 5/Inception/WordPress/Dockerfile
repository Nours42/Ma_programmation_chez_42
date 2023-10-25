# rappel des consignes : WordPress avec php-fpm configuré

FROM debian:9

RUN apk update && apk upgrade && apk add \
			openssl			\
			nginx			\
			curl			\
			vim				\
			sudo

RUN	rm -f /etc/nginx/nginx.conf

COPY ./config/nginx.conf /etc/nginx/nginx.conf
COPY scripts/setup_nginx.sh /setup_nginx.sh

RUN chmod -R +x /setup_nginx.sh

EXPOSE	443

ENTRYPOINT [ "sh", "setup_nginx.sh" ]