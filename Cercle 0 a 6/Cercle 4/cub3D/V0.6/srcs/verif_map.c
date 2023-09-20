/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/20 16:09:02 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	search_map(t_data *data)
// {
// 	if (map_validation(data))
// 		return (1);
// 	else
// 		ft_printf("structure de la map :\t\t\033[32mOK\033[0m\n\n");
// 	return (0);
// }

// int	is_valid_line(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\n')
// 	{
// 		if (s[i] == ' ' || s[i] =='\t' || s[i] =='0' || s[i] =='1'
// 			|| s[i] =='E' || s[i] =='N' || s[i] =='S' || s[i] =='W')
// 		i++;
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

// int map_validation(t_data *data)
// {
// 	int		i;

// 	i = 0;
// 	while (data->map[i])
// 	i++;
// 	while(data->map[i--])
// 	{
// 		if(is_valid_line(data->map[i]))
// 			return (titre_err(" car. incorrect "));
// 		else if (begin_by_one(data->map[i]) || ends_by_one(data->map[i]))
// 			return (titre_err(" mur ouvert "));
// 	}
// 	data->index_last_line = i - 1;
// 	return (0);
// }

// int	first_and_last_line_is_ones(t_data *data, int i)
// {
// 	int index;
// 	int	index_after_ones;

// 	index = spaces_or_tabs(data->map[i], 0);
// 	while (data->map[i][index] == 49)
// 		index++;
// 	index_after_ones = index;
// 	index = spaces_or_tabs(data->map[i], index_after_ones);
// 	if (data->map[i][index] == '\n')
// 		return (0);
// 	return (1);
// }

// int	spaces_or_tabs(char *s, int i)
// {
// 	while (s[i] == ' ' || s[i] == '\t')
// 		i++;
// 	return (i);
// }

int	browse_the_top_wall(t_data *data)
{
	// retour 1 si KO
	// retour 0 si OK
	int	index;
	int	line;
	
	index = 0;
	line = data->Map_first_line;
	while (data->map[line][index] == ' ' || data->map[line][index] == '\t')
		index++;
	while (data->map[line][index] == '1')
		index++;
	if (browse_the_right_wall(data, line + 1, index - 1))
		return (0);
	return (1);
}

int	browse_the_right_wall(t_data *data, int line, int index)
{
	ft_printf("je passe au mur de droite\n");
	int	new_line;
	// retour 1 si KO
	// retour 0 si OK
	// tant que je ne suis pas en bas
	new_line = 0;
	while (line != data->Map_last_line)
	{
		// ft_printf("new_line %d\n", new_line);
		// ft_printf("test ligne : %d et char : %d\n", line, index);
		// ft_printf("c'est : %c\n", data->map[line][index]);
		if (new_line == 0)
		{
			new_line = 1;
			while (index != 0)
			{
				if (data->map[line][index - 1] == '0')
					break;
				index--;
			}
		}
		else
		{

			if (data->map[line + 1][index] == '1')
			{
				new_line = 0;
				line++;
			}
			else if (data->map[line][index + 1] == '1')
			{
				while (data->map[line][index + 1] == '1')
					index++;
			}
			else
				return (1);
		}
	}
	if (browse_the_down_wall(data, line, index))
		return (0);
	return (1);
}

// int	browse_the_right_wall(t_data *data, int line, int index)
// {
// 	while (line != data->Map_last_line)
// 	{
// 		if (data->map[line + 1][index] == '1')
// 			line++;
// 		else if (data->map[line][index - 1] == '1')
// 			index--;
// 		else if (data->map[line][index + 1] == '1')
// 			index++;
// 		else
// 			return (0);
// 	}
// 	if (browse_the_down_wall(data, line, index))
// 		return (1);
// 	return (0);
// }

int	browse_the_down_wall(t_data *data, int line, int index)
{
	// retour 1 si KO
	// retour 0 si OK
	ft_printf("je passe au mur du bas\n");
	while (data->map[line][index] == '1')
		index--;
	if (browse_the_left_wall(data, line - 1, index + 1))
		return (0);
	return (1);
}

int	browse_the_left_wall(t_data *data, int line, int index)
{
	ft_printf("je passe au mur de gauche\n");
	int	new_line;
	// retour 1 si KO
	// retour 0 si OK
	// tant que je ne suis pas en haut
	new_line = 0;
	while (line != data->Map_first_line)
	{
		ft_printf("new_line %d\n", new_line);
		ft_printf("test ligne : %d et char : %d\n", line, index);
		ft_printf("c'est : %c\n", data->map[line][index]);
		if (new_line == 0)
		{
			new_line = 1;
			while (index)
			{
				if (data->map[line][index + 1] == '0')
					break;
				index++;
			}
		}
		else
		{

			if (data->map[line - 1][index] == '1')
			{
				new_line = 0;
				line--;
			}
			else if (data->map[line][index + 1] == '1')
			{
				while (data->map[line][index + 1] == '1')
					index++;
			}
			else
				return (0);
		}
	}
	if (line == data->Map_first_line)
		return (1);
	return (0);
}

int	begin_by_one(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == 49)
		return (1);
	return (0);
}

int	ends_by_one(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i -= 2;
	while (s[i] == ' ' || s[i] == '\t')
		i--;
	if (s[i] == '1')
		return (1);
	return (0);
}

void	find_start_end_of_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i])
		i++;
	i--;
	while (empty_line(data->map[i]))
		i--;
	data->Map_last_line = i;
	while (begin_by_one(data->map[i]) && ends_by_one(data->map[i]))
		i--;
	data->Map_first_line = i + 1;
}
