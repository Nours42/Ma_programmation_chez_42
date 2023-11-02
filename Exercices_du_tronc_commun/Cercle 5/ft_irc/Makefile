# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 10:38:18 by sdestann          #+#    #+#              #
#    Updated: 2023/11/02 16:04:42 by nours42          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME_SERV	=	ircserv
NAME_BOT	=	ircbot

SRCS_SERV	=	Utils.cpp \
				Console.cpp \
				server/main.cpp \
				server/Server.cpp \
				server/Channel.cpp \
				server/cmds/PassCommand.cpp \
				server/cmds/UserCommand.cpp \
				server/cmds/NickCommand.cpp \
				server/cmds/JoinCommand.cpp \
				server/cmds/PrivmsgCommand.cpp \
				server/cmds/QuitCommand.cpp \
				server/cmds/TopicCommand.cpp \
				server/cmds/PartCommand.cpp \
				server/cmds/ModeCommand.cpp \
				server/cmds/PingCommand.cpp \
				server/cmds/MotdCommand.cpp \
				server/cmds/VersionCommand.cpp \
				server/cmds/TimeCommand.cpp \
				server/cmds/InviteCommand.cpp \
				server/cmds/OperCommand.cpp \
				server/cmds/ListCommand.cpp \
				server/cmds/KickCommand.cpp \
				server/cmds/NamesCommand.cpp

OBJS_SERV	:=	$(addprefix obj/, $(SRCS_SERV:.cpp=.o))

# SRCS_BOT	:=	Utils.cpp \
# 				Console.cpp \
# 				bot/main.cpp \
# 				bot/Bot.cpp

# OBJS_BOT	:=	$(addprefix obj/, $(SRCS_BOT:.cpp=.o))

COMPILE		=	clang++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

### COLORS ###

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

### RULES ###

all: $(NAME_SERV)

obj/%.o: srcs/%.cpp
	@echo $(Y)Compiling [$@]...$(X)
	@/obj/mkdir -p $(dir $@)
	@$(COMPILE) $(FLAGS) -o $@ -c $< -I includes
	@printf $(UP)$(CUT)

$(NAME_SERV): $(OBJS_SERV)
	@$(COMPILE) $(FLAGS) $(OBJS_SERV) -o $(NAME_SERV)
	@echo $(G)Project $(NAME_SERV) by SDESTANN successfully compiled$(X)

# $(NAME_BOT): $(OBJS_BOT)
# 	@$(COMPILE) $(FLAGS) $(OBJS_BOT)-o $(NAME_BOT)
# 	@echo $(G)Project $(NAME_BOT) by SDESTANN successfully compiled$(X)

bonus: $(NAME_BOT)

run: $(NAME_SERV)
	./$(NAME_SERV) 6667 test
# run-bonus: $(NAME_BOT)
# 	./$(NAME_BOT) 127.0.0.1 6667 test general

clean:
	@echo $(R)Cleaning FT_IRC ! $(G)[$(OBJDIR)]...$(X)
	@/obj/rm -Rf obj/

fclean: clean
	@echo $(R)FCleaning FT_IRC ! $(G)[$(NAME_SERV)]...$(X)
	@/obj/rm -f $(NAME_SERV)
# @echo $(R)FCleaning FT_IRC ! $(G)[$(NAME_BOT)]...$(X)
# @/obj/rm -f $(NAME_BOT)

re: fclean all

.PHONY: all clean fclean re