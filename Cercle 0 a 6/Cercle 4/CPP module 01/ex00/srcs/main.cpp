/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:15:35 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/02 17:49:11 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	stack_zombie("Bob the Stack Zombie");
	Zombie	*heap_zombie = newZombie("Georges the Heap Zombie");

	randomChump("Lulu the Random Chump Zombie");
	delete heap_zombie;
	return (0);
}
