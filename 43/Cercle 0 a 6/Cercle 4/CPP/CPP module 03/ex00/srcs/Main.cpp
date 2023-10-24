/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:27:54 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/05 14:50:12 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int	main(void)
{
	std::string s1 = "Conan";
	std::string s2 = "Sonja";

	ClapTrap	claptrap1(s1);
	ClapTrap	claptrap2(s2);

	std::cout << std::endl;
	claptrap1.attack(s2);
	claptrap2.takeDamage(4);
	claptrap2.beRepaired(3);
	claptrap2.beRepaired(18);

	claptrap2.attack(s1);
	claptrap1.takeDamage(9);
	claptrap2.attack(s1);
	claptrap1.takeDamage(9);
	claptrap2.attack(s1);

	claptrap1.beRepaired(3);
	claptrap1.beRepaired(50);
	std::cout << std::endl;
	return (0);
}