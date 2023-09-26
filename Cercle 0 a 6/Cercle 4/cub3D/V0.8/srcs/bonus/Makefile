# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/09/26 12:49:14 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME = cub3d

HEADER_SRCS = cub3d_bonus.h
HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS_DIR = srcs/
SRCS =	break_prog_bonus.c			\
		check_arg_bonus.c 			\
		error_bonus.c				\
		get_map_colors_bonus.c		\
		go_around_the_walls_bonus.c	\
		main_bonus.c				\
		maps_bonus.c				\
		print_bonus.c				\
		utils_bonus.c				\
		utils_maps_bonus.c			\
		verif_fc_bonus.c			\
		verif_map_moove_bonus.c		\
		verif_map_bonus.c			\
		verif_player_bonus.c		\
		verif_textures_bonus.c		\
		windows_check_wall_bonus.c	\
		windows_init_bonus.c		\
		windows_mooves_bonus.c		\
		window_bonus.c

OBJDIR = objs

SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc -g
LIBFT		= ../../libft
LIBMLX		= ../../libmlx
LIBFT_DIR	= ../../libft/

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
	@$(CC) $(OBJ_SRCS) -L$(LIBFT) ../../libmlx/*.a -lXext -lX11 -lm -lft -o $(NAME)
	@echo $(G)Project CUB3D with BONUS by JMETEZEA and SDESTANN successfully compiled${X}
	gnome-terminal --command="nvlc ./objects/LotR.mp3"

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
