/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/07 17:44:06 by sdestann         ###   ########.fr       */
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

int	is_valid_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == ' ' || s[i] =='\t' || s[i] =='0' || s[i] =='1'
			|| s[i] =='E' || s[i] =='N' || s[i] =='S' || s[i] =='W')
		i++;
		else
			return (1);
	}
	return (0);
}

int	begin_by_one(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == 49)
		return (0);
	return (1);
}

int	ends_by_one(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i -= 2;
	while (s[i] == 32)
		i--;
	if (s[i] == 49)
		return (0);
	return (1);
}

int map_validation(char **cub)
{
	int		i;

	i = 5;
	while (cub[++i])
	{
		if(is_valid_line(cub[i]))
			return (err("erreur dans l'une des lignes de la map : caractere incorrect\n"));
		else if (begin_by_one(cub[i]))
			return (err("erreur dans l'une des lignes de la map"), 
				err(": ouverture dans un mur\n"));
		else if (ends_by_one(cub[i]))
			return (err("erreur dans l'une des lignes de la map"), 
				err(": fermeture dans un mur\n"));
	}
	return (0);
}

int	*player_coordonate(char **cub)
{
	int	i;
	int	j;
	int	coord[2];

	i = 0;
	j = 0;
	coord = (int*)malloc(sizeof(int) * 2);
	coord[0] = 0;
	coord[1] = 0;
	while (cub[i])
	{
		while (cub[i][j])
		{
			if (cub[i][j] =='E' || cub[i][j] =='N' || cub[i][j] =='S'
				|| cub[i][j] =='W')
				coord[0] = i;
				coord[1] = j;
			j++;
		}
		i++;
	}
	return (coord);
}

int	player_can_moove(char **cub)
{
	int	coord[2];

	coord = player_coordonate(cub);
	printf("%s\n", cub[coord[0] - 1]);
}

int	cub_validation(char **cub)
{
	if (ft_strncmp(cub[0], "NO", 2) != 0
		|| ft_strncmp(cub[1], "SO", 2) != 0
		|| ft_strncmp(cub[2], "WE", 2) != 0
		|| ft_strncmp(cub[3], "EA", 2) != 0)
		return (err("textures incorrectes\n"));
	if (ft_strncmp(cub[4], "F ", 2) != 0
		|| ft_strncmp(cub[5], "C ", 2) != 0)
		return (err("FLOOR ou CEILING manquant\n"));
	if (map_validation(cub))
		return (err("erreur dans la map\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*str;
	char	**cub;

	if (argc > 1)
	{
		cub = (char **)malloc(sizeof(char *) * 1024);
		fd = open(argv[1], O_RDONLY);
		i = -1;
		str = ft_get_next_line(fd);
		if (!str)
			return (err("erreur dans l'ouverture de la map\n"));;
		while (str)
		{
			cub[++i] = ft_strdup(str);
			free(str);
			str = ft_get_next_line(fd);
		}
		if (cub_validation(cub))
			return (err("la carte "), err(argv[1]), err(" est invalide\n"));
		else
			ft_printf("la carte est valide\n");
		ft_free_chars(cub);
	}
	else
		return (err("ou est la carte ?\n"));
}