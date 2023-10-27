/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/18 12:23:16 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <iomanip>

int main( void )
{
	std::list<int>	Tarr;
	int				i;

	i = 0;
	while (i < 100)
	{
		Tarr.push_back(i);
		i++;
	}
	
	srand(time(NULL));
	int choose = std::rand() % 120;

	std::cout << "la liste Tarr est compose des chiffres de 0 a 99" << std:: endl;
	std::cout << "le chiffre choose, aleatoire entre 0 et 119, est : " << choose << std:: endl;
	std::cout << "la fonction easyfind recherche la premiere occurence de choose dans Tarr" << std:: endl;
	std::cout << "si le nombre n'est pas trouve elle retourne une erreur" << std::endl;
	try
	{
		easyfind(Tarr, choose);
		std::cout << "Choose a ete trouve" << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "n'hesitez pas a relancer le programme pour changer le nombre choose" << std::endl;
	
	return (0);
}