/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:27:54 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 07:35:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "constructors called" << std::endl;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Dog* j = new Dog();
	const Cat* i = new Cat();

	std::cout << std::endl;
	std::cout << "types called" << std::endl;
	std::cout << std::endl;

	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "sounds called" << std::endl;
	std::cout << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "above we have logical cound of animal... and now..." << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Wrong constructor called" << std::endl;
	std::cout << std::endl;
	
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongCat* werecat = new WrongCat();

	std::cout << std::endl;
	std::cout << "wrong types called" << std::endl;
	std::cout << std::endl;

	std::cout << wmeta->getType() << std::endl;
	std::cout << werecat->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "wrong types called" << std::endl;
	std::cout << std::endl;

	wmeta->makeSound();
	werecat->makeSound();
	
	std::cout << std::endl;
	std::cout << "destructors of all this living beings called" << std::endl;
	std::cout << std::endl;

	return (0);
}