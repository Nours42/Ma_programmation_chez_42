# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 13:14:16 by sdestann          #+#    #+#              #
#    Updated: 2023/11/22 11:00:38 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SERV	:=	ircserv
#NAME_BOT	:=	ircbot
VERSION		:=	1.0
#ARCH		:=	x64

# -----------------------------------------------------------------------------
# COMPILATION
# -----------------------------------------------------------------------------
SRCS_SERV	:=	Channel.cpp		\
				Commands.cpp	\
				Interpretor.cpp	\
				Logs.cpp		\
				main.cpp		\
				Server.cpp		\
				User.cpp

OBJS_SERV	:=	$(addprefix srcs/, $(SRCS_SERV:.cpp=.o))

#SRCS_BOT	:=	Utils.cpp \
#				Console.cpp \
#				bot/main.cpp \
#				bot/Bot.cpp

#OBJS_BOT	:=	$(addprefix bin/, $(SRCS_BOT:.cpp=.o))

CC			:=	clang++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98

# -----------------------------------------------------------------------------
# COLORS
# -----------------------------------------------------------------------------
__RED		:=	"\033[1;31m"
__GREEN		:=	"\033[1;32m"
__YELLOW	:=	"\033[1;33m"
__BLUE		:=	"\033[1;36m"
__WHITE		:=	"\033[1;37m"
__EOC		:=	"\033[0;0m"

# -----------------------------------------------------------------------------
# RULES
# -----------------------------------------------------------------------------
bin/%.o: srcs/%.cpp
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -o $@ -c $< -I includes
	@echo ${__GREEN}"Compiling "${__WHITE}$<${__EOC}

all: ${NAME_SERV}

${NAME_SERV}: ${OBJS_SERV}
	@${CC} ${CFLAGS} ${OBJS_SERV} -o ${NAME_SERV}
	@echo ${__GREEN}"Finished "${__WHITE}${NAME_SERV}" v"${VERSION}" by JMETEZEA & SDESTANN"${__EOC}

${NAME_BOT}: ${OBJS_BOT}
	@${CC} ${CFLAGS} ${OBJS_BOT} -o ${NAME_BOT}
	@echo ${__GREEN}"Finished "${__WHITE}${NAME_BOT}" v"${VERSION}" bin target"${__EOC}

bonus: ${NAME_BOT}

run: ${NAME_SERV}
	./${NAME_SERV} 6667 test
run-bonus: ${NAME_BOT}
	./${NAME_BOT} 127.0.0.1 6667 test general

clean:
	@rm -rf srcs/*.o

fclean: clean
	@rm -rf ${NAME_SERV} ${NAME_BOT}
	@echo ${__BLUE}"Cleaned "${__WHITE}".o target(s)"${__EOC}

re: fclean all
re-all: fclean ${NAME_SERV} ${NAME_BOT}

.PHONY: all fclean clean re
