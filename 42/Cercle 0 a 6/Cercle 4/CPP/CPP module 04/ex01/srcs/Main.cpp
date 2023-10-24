/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:27:54 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 11:14:13 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "constructors 10 animals : 5 dogs and 5 cats called" << std::endl;
	std::cout << std::endl;
	int i;

	const Animal* animal[10];
	i = -1;
	while (++i < 5)
		animal[i] = new Dog();
	i = 4;
	while (++i < 10)
		animal[i] =  new Cat();

	i = -1;
	while (++i < 10)
		animal[i]->makeSound();

	i = -1;
	while (++i < 10)
		delete animal[i];

	return (0);
}