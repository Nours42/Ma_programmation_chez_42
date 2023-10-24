# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/09/28 12:14:41 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME = cub3D

HEADER_SRCS = cub3d.h
HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS_DIR = srcs/
SRCS =	break_prog.c				\
		break_prog2.c				\
		check_arg.c 				\
		error.c						\
		get_map_colors.c			\
		go_around_the_walls.c		\
		main.c						\
		maps.c						\
		print.c						\
		utils.c						\
		utils_maps.c				\
		verif_fc.c					\
		verif_map_moove.c			\
		verif_map.c					\
		verif_player.c				\
		verif_textures.c			\
		windows_calcul_distances.c	\
		windows_check_wall.c		\
		windows_init.c				\
		windows_mooves.c			\
		windows_mooves2.c			\
		window.c

OBJDIR = objs

SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc -g
LIBFT		= libft
LIBMLX		= libmlx
LIBFT_DIR	= libft/

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
	@make -s -C $(LIBMLX)
	@$(CC) $(OBJ_SRCS) -L$(LIBFT) ./libmlx/*.a -lXext -lX11 -lm -lft -o $(NAME)
	@echo $(G)Project CUB3D by JMETEZEA and SDESTANN successfully compiled${X}

$(OBJDIR)/%.o: $(SRCS_DIR)%.c $(HEADER) Makefile
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

norminette:
	@echo ${G}Norminette sources files${X}
	@norminette ./srcs
	@echo ${G}Norminette includes files${X}
	@norminette ./includes/
	@echo ${G}Norminette libft files${X}
	@norminette ./libft/

clean:
	@echo ${R}Cleaning CUB3D ${G}[${OBJDIR}]...${X}
	@make clean -s -C $(LIBFT)
	@/bin/rm -Rf ${OBJDIR}

fclean:
	@echo ${R}FCleaning CUB3D ${G}[${NAME}]...${X}
	@make fclean -s -C $(LIBFT)
	@/bin/rm -Rf ${OBJDIR}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
