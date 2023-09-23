/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:06:32 by kaly              #+#    #+#             */
/*   Updated: 2023/09/23 21:09:40 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gestion des espaces dans Floor ans Ceiling
// gestion des espaces dans textures

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "../libmlx/mlx.h"

# include <sys/types.h>
# include <sys/stat.h>

# define MLX_ERROR 1

# define PXL 50

# define WINDOW_H 1080
# define WINDOW_W 1920

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	
	char	**map;
	int		NO_texture;
	int		SO_texture;
	int		WE_texture;
	int		EA_texture;
	int		index_Floor;
	int		index_Ceiling;
	int		line_Floor;
	int		line_Ceiling;
	int		Floor_first_color;
	int		Floor_second_color;
	int		Floor_third_color;
	int		Ceiling_first_color;
	int		Ceiling_second_color;
	int		Ceiling_third_color;
	int		Map_last_line;
	int		Map_first_line;
	int		line;
	int		index;
	int		first_index;
	size_t	size_max;

	void	*file;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	int		line_length;

	int			color_r;
	int			color_g;
	int			color_b;

	int		color_map_hex_C;
	int		color_map_hex_F;

	int		player_x;
	int		player_y;
	int		player_orient;
	int		x;
	int		y;

	int		exit;

	// int		pxl;
	// int		map_x;
	// int		map_y;

	// int		pl_move;
	// int		pl_x;
	// int		pl_y;
	// int		player;
	// int		check_collect;
	// int		collect;
	// int		check_exit;

	// int		exit_x;
	// int		exit_y;
	// int		exit_is_open;
}	t_data;

//		break_prog		//

void	ft_clean_when_verif_map_ko(t_data *data);
int		ft_quit(t_data *data);

//		check_arg		//

int		ft_comp_cub(char *arg, char *str);
void	ft_check_arg(int argc, char **argv);

//		error			//

int		err(char *str);
int		err_map(char *str);

//		main			//

void	init_data(t_data *data);
int		main(int argc, char **argv);

//		maps			//

int		ft_check(int argc, char **argv, t_data *data);
void	resize_map(t_data *data);
void	add_spaces(t_data *data);
void    *ft_realloc_space(void *ptr, size_t original_size, size_t new_size);
void	*ft_memset2(void *b, int c, size_t len);

//		print			//

void	titre(char *str);
int		titre_err(char *str);
void	line_up(int i);
void	line(int i);

//		utils			//

void	print_map(t_data *data, int i);
int		empty_line(char *c);
void	print_map_n(t_data *data, int i);
char	*make_color_hex(int n);
int		ft_htoi(char *s);
char	*get_map_color(char *s, int l, t_data *data);

// 		verif_fc.c		//

int 	search_floor_or_ceiling(t_data *data, char *c);
int 	floor_ceiling_found(t_data *data);
int		floor_format_validation(t_data *data);
int		ceiling_format_validation(t_data *data);
int		floor_ceiling_validation(t_data *data);

//		verif_map_moove		//

int		test_map_ok (t_data *data, int i);
int		verif_sides(t_data *data, int i, int j);
int 	verif_up_or_down(t_data *data, int i, int j);
void	go_sides(t_data *data, int i, int j);
void	go_up_or_down(t_data *data, int i, int j);

//		verif_map		//

void	first_step(t_data *data);
int		go_around_the_walls(t_data *data);
int		begin_by_one(char *s);
int		ends_by_one(char *s);
void	find_start_end_of_map(t_data *data);

//		verif_player	//

void	player_coordonate(t_data *data);
int		only_one_player(t_data *data);

// 		verif_textures.c		//

int		search_textures(t_data *data, char *texture);
int		texture_validation(t_data *data);

//		window			//

int		handle_keypress(int keysym, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		calcul_distance(t_data *data);
void	affiche_un_mur(t_data *data, int i);
void	ft_fill_floor(t_data *data);
int		render(t_data *data);
void	ft_create_window(t_data *data);

#endif
