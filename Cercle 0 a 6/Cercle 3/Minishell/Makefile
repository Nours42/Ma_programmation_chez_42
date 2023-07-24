# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/07/25 00:37:34 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME = minishell

HEADER_SRCS = minishell.h
HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS_DIR = srcs/
SRCS =	cd.c		\
		dobble_and.c\
		execute.c	\
		exit.c		\
		export.c	\
		free.c		\
		free_pipe.c	\
		init.c		\
		main.c		\
		parse.c		\
		pipe.c		\
		print.c		\
		ptd.c		\
		pwd.c		\
		redirect.c	\
		signals.c	\
		token.c		\
		unset.c 	\
		utils.c
OBJDIR = objs

SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

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

all: ${NAME}

%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ_SRCS}
	@echo $(G)Creating libft files$(X)
	@make -s -C $(LIBFT)
	@$(CC) $(OBJ_SRCS) -L$(LIBFT) -lft -lreadline -o $(NAME)
	@echo $(G)Project MINISHELL by JMETEZEA and SDESTANN successfully compiled${X}

$(OBJDIR)/%.o: $(SRCS_DIR)%.c $(HEADER) Makefile
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@echo ${R}Cleaning MINISHELL ${G}[${OBJDIR}]...${X}
	@make clean -s -C $(LIBFT)
	@/bin/rm -Rf ${OBJDIR}

fclean:
	@echo ${R}FCleaning MINISHELL ${G}[${NAME}]...${X}
	@make fclean -s -C $(LIBFT)
	@/bin/rm -Rf ${OBJDIR}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
