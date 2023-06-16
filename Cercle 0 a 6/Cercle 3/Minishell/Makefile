# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/06/16 15:04:27 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME = minishell

HEADER_SRCS	= minitalk.h
HEADER_DIR	= includes/
HEADER			= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS = \
main.c \
signals.c

OBJDIR = objs

SRCS_PATH 	= $(addprefix ${OBJDIR}/, $(SRCS))
OBJ_SRCS	= $(SRCS_PATH:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc -g
LIBFT		= libft
LFTA 		= ./libft/libft.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

### RULES ###
%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ_SRCS}
	@echo $(G)Creating libft files$(X)
	@make -s -C $(LIBFT)
	@$(CC) $(OBJ_SRCS) $(INCLUDES) $(LFTA) -o minishell
	@echo $(G)Project MINISHELL by JMETEZEA and SDESTANN successfully compiled${X}

all: ${NAME}
	@echo ${G}Success"   "[${NAME}]${X}

${OBJDIR}/%.o : ./srcs/%.c ${LFTA}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@echo ${R}Cleaning ${G}[${OBJDIR}]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo ${R}Cleaning ${G}[${NAME}]...${X}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
