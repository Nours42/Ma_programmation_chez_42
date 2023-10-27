/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:12 by nours42           #+#    #+#             */
/*   Updated: 2023/10/11 09:48:40 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

/////////////////// SUMMARY //////////////////
// canonical form Functions					//
// Function creation released by subject	//
// Exceptions Functions						//
//////////////////////////////////////////////

// canonical form Functions

Intern::Intern()
{
	std::cout << "A default Intern has been trained" << std::endl << std::endl;
}

Intern::~Intern()
{
	std::cout << "A Intern has been fired, but who care ?" << std::endl;
}

Intern::Intern(Intern const & ref)
{
	(void)ref;
	std::cout << "A Intern has been constructed by copyref" << std::endl;
}

Intern & Intern::operator=(Intern const & ref)
{
	(void)ref;
	std::cout << "A Intern has been constructed by clonage (operator =)" << std::endl;
	return (*this);
}

// Function creation released by subject

static AForm	*new_robo(std::string target)
{
	AForm	*robo = new RobotMyRequestForm(target);
	return (robo);
}

static  AForm	*new_president(std::string target)
{
	AForm	*president = new PresidentialPardonForm(target);
	return (president);
}

static  AForm	*new_shrub(std::string target)
{
	AForm	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
	int i;

	i = -1;
	AForm	*(*fct[3])(std::string target) = { new_robo, new_president, new_shrub};
	std::string	msg[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm	*ret = NULL;
	while (++i < 3)
	{
		if (form_name == msg[i])
			ret = fct[i](form_target);
	}
	if (ret)
		std::cout << "Intern creates " << *ret << std::endl;
	else
		throw (Intern::Exception());
	return (ret);
}


// Exceptions functions

const char*	Intern::Exception::what() const throw()
{
	return ("An Intern have found an error, take the prestige if you can and fired him, or her");
}
