# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 10:38:18 by sdestann          #+#    #+#              #
#    Updated: 2023/10/05 17:02:00 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

# il manque a creer le DiamondTrap.cpp et hpp avec les fonctions et attributs du sujet
# le makefile est fait (la partie facile)

NAME = DiamondTrap

HEADER_SRCS =	ClapTrap.hpp	\
				FragTrap.hpp	\
				DiamondTrap.hpp	\
				ScavTrap.hpp
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS_DIR	=	srcs/
SRCS		=	Main.cpp		\
				ClapTrap.cpp	\
				DiamondTrap.cpp	\
				FragTrap.cpp	\
				ScavTrap.cpp

OBJDIR		=	objs

SRCS_PATH	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS	=	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

COMPILE		=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

### RULES ###

all: $(NAME)

$(OBJDIR)/%.o: $(SRCS_DIR)%.cpp $(HEADER) Makefile
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${COMPILE} ${FLAGS} -I./$(HEADER_DIR) -c -o $@ $<
	@printf ${UP}${CUT}

$(NAME): ${OBJ_SRCS}
	@$(COMPILE) ${FLAGS} -o $(NAME) ${OBJ_SRCS}
	@echo $(G)Project DiamondTrap ! by SDESTANN successfully compiled${X}

clean:
	@echo ${R}Cleaning DiamondTrap ! ${G}[${OBJDIR}]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo ${R}FCleaning DiamondTrap ! ${G}[${NAME}]...${X}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re