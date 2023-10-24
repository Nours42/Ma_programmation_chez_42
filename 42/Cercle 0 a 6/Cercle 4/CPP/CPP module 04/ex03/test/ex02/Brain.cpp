/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:04:47 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/20 09:21:43 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (unsigned int i = 0; i < _MaxIdeas; i++)
	{
		_ideas[i] = "-- no idea yet --";
	}
	std::cout << COLOR_WHITE << "[Brain] default constructor called\n" << COLOR_DEFAULT;
}

Brain::Brain(Brain const & input)
{
	*this = input;
	std::cout << COLOR_WHITE << "[Brain] copy constructor called\n";
}

Brain const & Brain::operator=(Brain const & input)
{
	for (unsigned int i = 0; i < _MaxIdeas; i++)
	{
		this->_ideas[i] = input._ideas[i];
	}
	std::cout << COLOR_WHITE << "[Brain] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << COLOR_WHITE << "[Brain] destructor called\n" << COLOR_DEFAULT;
}

void	Brain::setIdea(unsigned int index, std::string idea)
{
	if (index < _MaxIdeas)
		this->_ideas[index] = idea;
}

std::string	Brain::getIdea(unsigned int index) const
{
	if (index < _MaxIdeas)
		return (this->_ideas[index]);
	return ("invalid index!");
}
