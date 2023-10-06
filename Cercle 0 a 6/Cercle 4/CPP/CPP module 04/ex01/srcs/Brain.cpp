/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 08:06:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

Brain::Brain()
{
	int i;

	i = -1;
	std::cout << "Brain full of ideas constructor called" << std::endl;
	this->ideas = new std::string[100];
	while (++i < 100)
		this->ideas[i] = "\033[34mideas\033[0m";

}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain & ref)
{
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = ref.ideas;
}

Brain & Brain::operator=(const Brain & rhs)
{
	std::cout << "Brain constructor by operator = called" << std::endl;
	this->ideas = rhs.ideas;
	return (*this);
}

void Brain::makeSound( void ) const
{
	std::cout << this->ideas << " say : What's is the generic Brain sound ? birds maybe ?" << std::endl;
}

std::string Brain::getIdeas( void ) const
{
	return ("My ideas is " + this->ideas);
}