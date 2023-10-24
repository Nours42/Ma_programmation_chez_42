# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:55:35 by sdestann          #+#    #+#              #
#    Updated: 2022/11/23 11:39:43 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_strlen.c \
		srcs/ft_strcmp.c \
		srcs/ft_swap.c

OC = ${SRCS:.c=.o}

INCL = includes
NAME = libft.a
LIBC = ar rc
LIBR = ranlib
GCC = gcc
RMF = rm -f
FLAG = -Wall -Wextra -Werror

.c.o:
	${GCC} ${FLAG} -c $< -o ${<:.c=.o} -I ${INCL}

all:	${OC}
	${LIBC} ${NAME} ${OC}
	${LIBR} ${NAME}

clean:
	${RMF} ${NAME} ${OC}

fclean:	clean
	${RMF} ${NAME}

re:	fclean all
