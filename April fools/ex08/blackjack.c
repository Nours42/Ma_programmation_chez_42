/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:50:48 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/03 09:59:45 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

{
	switch (c)
	{
		case "2" :
			return (2);
		case "3" :
			return (3);
		case "4" :
			return (4);
		case "5" :
			return (5);
		case "6" :
			return (6);
		case "7" :
			return (7);
		case "8" :
			return (8);
		case "9" :
			return (9);
		case "T" :
			return (10);
		case "J" :
			return (10);
		case "Q" :
			return (10);
		case "K" :
			return (10);
		case "A" :
			if(face)
				return (11);
	}
}

int	main (int argc, char **argv)
{
	int	score;
	int face;

	score = 0;

}