/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 05:25:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/03 05:54:22 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// int main()
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA edmond("Edmond", club);
// 		edmond.attack();
// 		club.setType("some other type of club");
// 		edmond.attack();
// 	}
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB georges("Georges");
// 		georges.setWeapon(club);
// 		georges.attack();
// 		club.setType("some other type of club");
// 		georges.attack();
// 	}
// }

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		// jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}