# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 11:01:13 by sebastien         #+#    #+#              #
#    Updated: 2023/03/16 11:56:19 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 	* CREATE A MAKEFILE TO COMPILATE OUR LIB * #

# 	* functions that must be compiled through our makefile
SRCS	= ft_atoi.c \
	ft_atol.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c\
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

OBJS 	= $(SRCS:.c=.o)

BONUS	= ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

BONUS_OBJS	= $(BONUS:.c=.o)

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Werror -Wextra

NAME = libft.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) 

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)


# 	* prevent our program from crashing if there is any folder or \
file with the name of one of our "rules"
.PHONY:	all clean fclean re bonus
