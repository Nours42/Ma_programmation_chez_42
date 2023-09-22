/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/19 15:57:25 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// verif qu'il y ait bien les renseignements demandes par le sujet sur la map
// 
// pour rappel il s'agit de :
// 
// TEXTURES
// 
// un texture pour les murs NORTH dont la ligne commence par NO et un chemin
// un texture pour les murs SOUTH dont la ligne commence par NO et un chemin
// un texture pour les murs WEST dont la ligne commence par NO et un chemin
// un texture pour les murs EAST dont la ligne commence par NO et un chemin
// 
// si le chemin est inaccessible prevoir une texture "par defaut"
// avec un message qui l'annonce.
// "la texture XX situee a ./chemin n'a pas pu etre ouverte, elle est remplacee
// par la texture par defaut"
// 
// FLOOR & CEILING
// 
// une couleur de sol et de plafond ecritent telles que :
// F XXX, XXX, XXX ou O XXX, XXX, XXX ou XXX est un chiffre entre 0 et 255.
// 
// si la syntaxe n'est pas respectee ou si le chiffre est negatif ou au dela 
// de 255
// prevoir un remplacement avec une phrase qui s'affiche.
// "la couleur de F ou C n'est pas compatible avec le sujet, elle est 
// remplacee par..."
// 
// MAP
// 
// la map est composee de 0 et de 1, 1 pour un mur et 0 pour un espace vide
// un caractere N, S, W ou E pour dire ou apparait le joueur et dans quelle
// direction il regarde.
// 
// premier passage de ces lignes pour verifier qu'elles ont toutes la meme
// longueur. Si ce n'est pas le cas, message d'erreur demandant de completer
// les manques par des 0 ou des 1.
// "votre carte n'est pas complete merci de la completer afin que chaque ligne
// comporte autant de caracteres"
// prevoir la possibilite de remplir les caracteres manquant par des 0.
//





int	ft_check(int argc, char **argv, t_data *data)
{
	int		fd;
	int		i;
	char	*str;
	

	if (argc > 1)
	{
		data->map = (char **)malloc(sizeof(char *) * 100);
		fd = open(argv[1], O_RDONLY);
		i = 0;
		str = ft_get_next_line(fd);
		if (!str)
			return (err("erreur dans l'ouverture de la map\n"));;
		while (str)
		{
			data->map[i++] = ft_strdup(str);
			free(str);
			str = ft_get_next_line(fd);
		}
		data->map[i] = 0;
		ft_printf("\e[1;1H\e[2J");
		titre(" TEST DE LA MAP ");
		if (texture_validation(data) || floor_ceiling_validation(data))
			return(titre_err(" MAP : KO "));
		else
			titre(" MAP : OK ");
		player_coordonate(data);
		titre(" TEST PERSO ");
		if (only_one_player(data))
			return (titre_err(" too or not perso "));
		else
			ft_printf("Personnage : 1\t\t\t\033[32mOK\033[0m\n");
		// if (player_can_moove(data))
		// 	return (titre_err(" pers moove "));
		// else
		// {
		// 	ft_printf("Personnage : peut bouger\t\033[32mOK\033[0m\n\n");
		// 	titre(" PERSO : OK ");
		// }
	}
	else
		return (err("ou est la carte ?\n"));
	return (0);
}