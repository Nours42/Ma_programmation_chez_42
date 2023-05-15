# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/05/02 11:09:50 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME		=	push_swap

OBJDIR		= objs/
SRCDIR		= srcs/
SRC			= 	ft_check.c \
				ft_free_lon.c \
				ft_index.c \
				ft_list.c \
				ft_lon.c \
				main.c \
				move_p_s.c \
				move_r.c \
				move_rr.c \
				move.c \
				russian_doll_sort.c \
				small_sort.c

OBJ			= $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC			=	gcc -g
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ./includes -I ./libft/includes

PSH 		= includes/push_swap.h
LFTA		= -Llibft -lft
LIBFT		= libft
BONUSDIR	= bonus

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


### RULES ###

all: $(NAME)
	@echo $(GREEN)Project PUSH_SWAP by SDESTANN successfully compiled${NOC}

$(NAME): $(OBJ)
	@echo $(GREEN)Creating libft files$(CYAN)
	@make -s -C $(LIBFT)
	@echo ${YELLOW}Create .o files...${NOC}
	@echo ${CYAN}Create push_swap...${NOC}
	@$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LFTA)


${OBJDIR}%.o : $(SRCDIR)%.c $(OBJDIR)
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJDIR) :
	@echo ${VIOLET}Create objs folder...${NOC}
	@/bin/mkdir -p ${OBJDIR}

bonus: re
	@echo $(GREEN)Creating bonus files$(CYAN)
	@make -s -C $(BONUSDIR)
	@cp bonus/checker checker
	
clean:
	@echo ${BLUE}Cleaning LIBFT files...${NOC}
	@make clean -s -C $(LIBFT)
	@make clean -s -C $(BONUSDIR)
	@echo ${RED}Cleaning objects files...${NOC}
	@/bin/rm -Rf ${OBJDIR}
	@/bin/rm -f checker

fclean:
	@echo $(BLUE)Cleaning libft with vacuum$(NOC)
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -f ${NAME}
	@make fclean -s -C $(LIBFT)
	@make fclean -s -C $(BONUSDIR)
	@/bin/rm -f checker

re: fclean all

.PHONY: re, fclean, clean, bonus