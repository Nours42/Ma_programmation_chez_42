/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 11:18:46 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

Brain::Brain()
{
	int i;

	this->ideas = new std::string[100];
	i = -1;
	while (++i < 100)
		this->ideas[i] = "\033[34mideas\033[0m";
	std::cout << "\033[34mBrain\033[0m full of ideas constructor called" << std::endl;

}

Brain::~Brain()
{
	delete[] (this->ideas);
	std::cout << "\033[34mBrain\033[0m destructor called" << std::endl;
}

Brain::Brain(Brain & ref)
{
	int i;

	std::string *ref_ideas = ref.getIdeas();
	this->ideas = new std::string[100];
	i = -1;
	while (++i < 100)
		this->ideas[i] = ref_ideas[i] + "stolen by copy";
	std::cout << "\033[34mBrain\033[0m copy constructor called" << std::endl;
}

Brain & Brain::operator=(const Brain & rhs)
{
	int i;

	i = -1;
	this->ideas = new std::string[100];
	while (++i < 100)
		this->ideas[i] = rhs.ideas[i] + "stolen by operator";
	std::cout << "\033[34mBrain\033[0m constructor by operator = called" << std::endl;
	return (*this);
}

std::string *Brain::getIdeas()
{
	return (this->ideas);
}