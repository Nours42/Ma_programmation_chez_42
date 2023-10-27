/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_prog2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:37:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/28 12:01:16 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_clean_when_textures_ko(t_data *data)
{
	ft_quit2(data, 0);
	free(data);
	exit (EXIT_FAILURE);
}
