FROM debian:12

WORKDIR /app

RUN apt-get update
RUN apt-get upgrade -y
#RUN apt-get -y install 
RUN apt-get update
RUN apt-get upgrade -y

RUN mkdir -p ircserv
COPY ./git_irc ./ircserv

CMD "make"
