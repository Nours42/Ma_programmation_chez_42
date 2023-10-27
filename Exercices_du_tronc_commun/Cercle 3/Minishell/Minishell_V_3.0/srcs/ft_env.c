/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:30:25 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/11 08:44:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_envp(t_data *data, int o)
{
	int		i;
	t_envp	*show_envp;

	show_envp = data->envp;
	if (!show_envp)
		return ;
	i = 1;
	while (show_envp != NULL)
	{
		printf("nb %d : %s\n", i, show_envp->str);
		show_envp = show_envp->next;
		i++;
	}
	if (o == 1)
		ft_printf("export what ?\n");
	free(show_envp);
	exit(EXIT_SUCCESS);
}
