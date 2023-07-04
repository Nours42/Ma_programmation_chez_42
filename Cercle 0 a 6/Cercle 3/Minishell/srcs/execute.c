/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/04 15:33:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_command(t_data *data, char **envp)
{
	// 1 - Verifier le niveau de data->lvl
	// 2 - Remplacer les $xxx en recherchant dans l'env les exports
	// 3 - Executer les commandes du lvl le plus haut, puis -- etc
	data->pid = fork();
	//ft_printf("exec command\n");
	if (data->pid == 0)
	{
		data->str_temp2 = get_cmd(data->cmd_paths, data->cmd_args[0]);
		if (data->str_temp2 != NULL)
			execve(data->str_temp2, data->cmd_args, envp);
		else
		{
			ft_printf("%s : commande introuvable\n", data->cmd_args[0]);
			exit(EXIT_FAILURE);
		}
		perror("Erreur d'exécution de la commande\n");
		exit(EXIT_FAILURE);
	}
	else if (data->pid < 0)
		perror("Erreur lors de la création du processus\n");
	else
		wait(NULL);
}

// cherche les $ dans les args et les remplaces par la valeur en ENV.
// il = index of the letter in the args
// in = new index of letter in args
void	give_me_the_money(t_data *data, int i)
{
	int		il;
	int		in;
	int		zero;
	char	*temp_str;
	t_envp	*list;
	
	list = data->env;
	il = 0;
	while (data->cmd_args[i][il] != '$')
		il++;
	if (data->cmd_args[i][il + 1] == '$')
		return ; // je saute a l'argument suivant
	else
	{
		//j'ai trouve un arg avec un et un seul $ dans l'arg, je verifie qu'il corresponde a qq chose dans env
		// je commence par mesurer la taille du mot a chercher dans envp
		in = 0;
		while (data->cmd_args[i][il + in])
			in++;
		//je malloc une size de in
		in--;
		temp_str = (char *)malloc(sizeof(char) * in);
		//je copie les caracteres dedans;
		zero = 0;
		while (data->cmd_args[i][il + 1 + zero])
		{
			temp_str[zero] = data->cmd_args[i][il + 1 + zero];
			zero++;
		}
		temp_str[zero] = '\0';
	}
	zero = 0;
	// maintenant je cherche temp_str dans env suivi d'un '='
	while (list && zero == 0)
	{
		if ((ft_strncmp(temp_str, list->str, ft_strlen(temp_str)) == 0) 
			&& (list->str[ft_strlen(temp_str)] == '='))
		{
			ft_printf("la variable est trouve\n%s\n", list->str);
			// longueur de mon arg avant : ft_strlen(data->cmd_args[i])
			// longueur de la ligne trouvee dans env : ft_strlen(list->str)
			// je dois commencer a le recuperer apres le = qui est a l'index in + 1
			
			// maintenant je cree le nouvel arg
			// je le malloc
			// je remplace dans data->cmd_args
			zero = 1;
		}
		list = list->next;
	}
}