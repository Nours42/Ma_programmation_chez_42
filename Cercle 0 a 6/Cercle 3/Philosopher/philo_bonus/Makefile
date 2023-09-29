# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/09/29 14:41:00 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME			=	philo

CC				=	gcc -g -pthread
CFLAGS			=	-Wall -Wextra -Werror
INCLUDES		=	-I ./includes

HEADER_SRCS		= philo.h
HEADER_DIR		= includes/
HEADER			= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MANDATORY_SRCS	= routine.c main.c utils.c init.c check.c
MANDATORY_DIR	= srcs/
MANDATORY_PATH	= $(addprefix $(MANDATORY_DIR), $(MANDATORY_SRCS))
OBJ_MANDATORY	= $(MANDATORY_PATH:.c=.o)

OBJ_DIR		= objs/

### COLORS ###

NOC         = "\033[0m"
BLACK       = "\033[1;30m"
RED         = "\033[1;31m"
GREEN       = "\033[1;32m"
YELLOW      = "\033[1;33m"
BLUE        = "\033[1;34m"
VIOLET      = "\033[1;35m"
CYAN        = "\033[1;36m"
WHITE       = "\033[1;37m"


### RULES ###
%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_MANDATORY)
	@$(CC) $(OBJ_MANDATORY) $(INCLUDES) -o $(NAME)
	@echo $(GREEN)Project PHILOSOPHER by SDESTANN successfully compiled${NOC}

all: $(NAME)
	
clean:
	@echo ${YELLOW}Cleaning MANDATORY files...${NOC}
	@/bin/rm -rf $(OBJ_MANDATORY)
	@echo ${GREEN}it s clean${NOC}

fclean:
	@echo ${YELLOW}Cleaning MANDATORY files...${NOC}
	@/bin/rm -rf $(OBJ_MANDATORY)
	@echo ${BLUE}Cleaning $(NAME) file...${NOC}
	@rm -f $(NAME)
	@echo ${GREEN}it s f****** clean${NOC}

re: fclean all

.PHONY: re, fclean, clean, bonus, all