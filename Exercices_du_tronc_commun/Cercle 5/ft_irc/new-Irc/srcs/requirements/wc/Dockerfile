FROM debian:12

WORKDIR /app

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install ca-certificates dirmngr gpg-agent apt-transport-https weechat-curses weechat-plugins weechat-python weechat-perl
RUN apt install netcat-traditional
RUN apt-get update
RUN apt-get upgrade -y
