/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:59:57 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 18:40:18 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	Animal	* animal_array[10];
	for (unsigned int i = 0; i < 5; i++)
	{
		animal_array[i] = new Cat();
		animal_array[i + 5] = new Dog();
	}
	
	const Animal* animal = new Animal();
	std::cout << "Hi, I am a " << animal->getType() << " and I don't have a Brain!" << std::endl;
	animal->makeSound();
	delete animal;
	std::cout << std::endl;
	
	
	const Dog* dog = new Dog();
	std::cout << "Hi, I am a " << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << "I am thinking of: " << dog->getIdea(0) << std::endl;
	std::cout << "I have a new idea! FOOD!\n";
	dog->setIdea(0, "I want to eat something. FOOD");
	std::cout << "I am thinking of: " << dog->getIdea(0) << std::endl;
	const Dog * dog_copy = new Dog(*dog);

	std::cout << "Hi, I am a " << dog_copy->getType() << " " << std::endl;
	std::cout << "I am thinking of: " << dog_copy->getIdea(0) << std::endl;
	std::cout << "I have a new idea! Hunting a Cat!\n";
	dog_copy->setIdea(1, "I want to hunt a Cat. Cat");
	std::cout << "I am thinking of: " << dog_copy->getIdea(1) << std::endl;
	dog_copy->makeSound();

	std::cout << "I am thinking of: " << dog->getIdea(1) << std::endl;	
	delete dog_copy;
	delete dog;
	std::cout << std::endl;
	
	
	const Cat* cat = new Cat();
	std::cout << "Hi, I am a " << cat->getType() << " " << std::endl;
	std::cout << "I am thinking of: " << cat->getIdea(0) << std::endl;
	std::cout << "I have a new idea! FOOD!\n";
	cat->setIdea(0, "I want to eat something. FOOD");
	std::cout << "I am thinking of: " << cat->getIdea(0) << std::endl;
	cat->makeSound();
	const Cat * cat_copy = new Cat(*cat);
	delete cat;
	std::cout << "Hi, I am a " << cat_copy->getType() << " " << std::endl;
	std::cout << "I am thinking of: " << cat_copy->getIdea(0) << std::endl;
	std::cout << "I have a new idea! Hunting a Mouse!\n";
	cat_copy->setIdea(1, "I want to hunt a Mouse. Mouse");
	std::cout << "I am thinking of: " << cat_copy->getIdea(1) << std::endl;
	cat_copy->makeSound();
	delete cat_copy;
	std::cout << std::endl;


	const WrongAnimal* wrong_animal = new WrongAnimal();
	std::cout << "Hi, I am a " << wrong_animal->getType() << " " << std::endl;
	std::cout << "I don't have a Brain yet. :-(\n";
	wrong_animal->makeSound();
	delete wrong_animal;
	std::cout << std::endl;


	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "Hi, I am a " << wrong_cat->getType() << " " << std::endl;
	std::cout << "I don't have a Brain yet too. :-((\n";
	wrong_cat->makeSound();
	delete wrong_cat;
	std::cout << std::endl;

	for (unsigned int i = 0; i < 5; i++)
	{
		delete animal_array[i];
		delete animal_array[i + 5];
	}
	return (0);
}
