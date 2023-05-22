# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/05/02 12:47:28 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME		=	checker

OBJDIR		= objs/
SRCDIR		= srcs/
SRC			= 	ft_check.c \
				ft_do_instructions.c \
				ft_free.c \
				ft_list.c \
				ft_lon.c \
				main.c \
				move_p_s.c \
				move_r.c \
				move_rr.c \
				move.c

OBJ			= $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC			=	gcc -g
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ./includes -I ../libft/includes
LFTA		= 	../libft/libft.a

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
	@echo $(GREEN)Project BONUS of PUSH_SWAP by SDESTANN successfully compiled${NOC}

$(NAME): $(OBJ)
	@echo ${YELLOW}Create .o files...${NOC}
	@echo ${CYAN}Create checker...${NOC}
	@make -s -C ../libft
	@$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LFTA)

${OBJDIR}%.o : $(SRCDIR)%.c $(OBJDIR)
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJDIR) :
	@echo ${VIOLET}BONUS TIME : Create objs folder...${NOC}
	@/bin/mkdir -p ${OBJDIR}
	
clean:
	@/bin/rm -Rf ${OBJDIR}

fclean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: re, fclean, clean