# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/05/24 11:27:48 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME		=	minishell

CC			=	gcc -g
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ./includes -I ./libft/includes

HEADER_SRCS	= minishell.h
HEADER_DIR	= includes/
HEADER			= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MANDATORY_SRCS	= main.c
MANDATORY_DIR	= srcs/
MANDATORY_PATH	= $(addprefix $(MANDATORY_DIR), $(MANDATORY_SRCS))
OBJ_SERVER	= $(MANDATORY_PATH:.c=.o)

BONUS_SRCS	= main_bonus.c
BONUS_DIR	= bonus/
BONUS_PATH	= $(addprefix $(BONUS_DIR), $(BONUS_SRCS))
OBJ_BONUS	= $(BONUS_PATH:.c=.o)

LFTA		= ./libft/libft.a
LIBFT		= libft
BONUSDIR	= bonus
OBJ_DIR		= objs

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

$(NAME): $(OBJ_SERVER) $(OBJ_CLIENT)
	@echo $(GREEN)Creating libft files$(CYAN)
	@make -s -C $(LIBFT)
	@$(CC) $(OBJ_CLIENT) $(INCLUDES) $(LFTA) -o client
	@$(CC) $(OBJ_SERVER) $(INCLUDES) $(LFTA) -o server
	@echo $(GREEN)Project MINISHELL by JMETEZEA & SDESTANN successfully compiled${NOC}

all: $(NAME)
	
clean:
	@echo ${BLUE}Cleaning LIBFT files...${NOC}
	@make clean -s -C $(LIBFT)
	@echo ${YELLOW}Cleaning MANDATORY files...${NOC}
	@/bin/rm -rf $(OBJ_CLIENT)
	@/bin/rm -rf $(OBJ_SERVER)
	@echo ${RED}Cleaning BONUS files, if they re existing ...${NOC}
	@/bin/rm -rf $(OBJ_BONUS)
	@echo ${GREEN}it s clean${NOC}

fclean:	
	@echo ${BLUE}Fcleaning LIBFT files...${NOC}
	@make fclean -s -C $(LIBFT)
	@echo ${YELLOW}Cleaning MANDATORY files...${NOC}
	@/bin/rm -rf $(OBJ_CLIENT)
	@/bin/rm -rf $(OBJ_SERVER)
	@echo ${RED}Cleaning BONUS files, if they re existing ...${NOC}
	@/bin/rm -rf $(OBJ_BONUS)
	@echo ${BLUE}Cleaning $(NAME) file...${NOC}
	@rm -f server client
	@echo ${GREEN}it s f****** clean${NOC}

re: fclean all

.PHONY: re, fclean, clean, bonus, all