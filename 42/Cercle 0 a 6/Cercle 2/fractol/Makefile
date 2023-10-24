# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/04/25 11:23:59 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
NAME		= fractol

### FOLDERS ###

OBJDIR		= objs/
SRCDIR		= srcs/
MLXDIR		= libmlx/
INCDIR		= includes/
LIBFTDIR	= libft/

### SOURCES ###

SRC			= controls.c \
				fractals.c \
				inputs.c \
				main.c \
				render.c

### OBJECTS ###

OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

### COMPILATION ###

CC			=	gcc -g -pthread
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ./includes -I ./libft/includes -I ./libmlx

### LIBFT ###

LFTA		= -Llibft -lft
LIBMLXA		= ./libmlx/*.a -lXext -lX11 -lm
LIBFT		= libft
LIBMLX		= libmlx

### COLORS ###

NOC         = "\033[0m"
BOLD        = "\033[1m"
UNDERLINE   = "\033[4m"
BLACK       = "\033[1;30m"
RED         = "\033[1;31m"
GREEN       = "\033[1;32m"
YELLOW      = "\033[1;33m"
BLUE        = "\033[1;34m"
VIOLET      = "\033[1;35m"
CYAN        = "\033[1;36m"
WHITE       = "\033[1;37m"

################################################################################

### RULES ###

all: $(NAME)
	@echo $(GREEN)Project FRACTOL by SDESTANN successfully compiled${NOC}

$(NAME): $(OBJ)
	@echo $(GREEN)Creating libft files$(CYAN)
	@make -s -C $(LIBFT)
	@make -s -C $(LIBMLX)
	@echo ${YELLOW}Create .o files...${NOC}
	@echo ${CYAN}Create fractol...${NOC}
	@$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LFTA) $(LIBMLXA)

${OBJDIR}%.o : $(SRCDIR)%.c $(OBJDIR)
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJDIR) :
	@echo ${VIOLET}Create objs folder...${NOC}
	@/bin/mkdir -p ${OBJDIR}

norminette:
	@echo ${GREEN}Norminette sources files${NOC}
	norminette $(SRCDIR)
	@echo ${GREEN}Norminette includes files${NOC}
	norminette $(INCDIR)
	@echo ${GREEN}Norminette libft files${NOC}
	norminette $(LIBFTDIR)

clean:
	@echo ${BLUE}Cleaning LIBFT files...${NOC}
	@make clean -s -C $(LIBFT)
	@echo ${VIOLET}Cleaning LIBMLX files...${NOC}
	@make clean -s -C $(LIBMLX)
	@echo ${RED}Cleaning OBJECTS files...${NOC}
	@/bin/rm -Rf ${OBJDIR}

fclean:
	@echo $(CYAN)Cleaning Project with 🤘 ultra vacuum of death 🤘$(NOC)
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -f ${NAME}
	@make fclean -s -C $(LIBFT)

re: fclean all

.PHONY: temporary, re, fclean, clean