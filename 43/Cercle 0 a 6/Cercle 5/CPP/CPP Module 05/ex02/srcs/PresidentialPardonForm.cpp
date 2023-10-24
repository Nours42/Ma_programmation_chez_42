/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:12 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:27:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/////////////////// SUMMARY //////////////////
// Getters Functions						//
// Canonical Form Functions					//
// Function creation released by subject	//
// Exceptions Functions						//
//////////////////////////////////////////////

// Getters Functions

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

// canonical PresidentialPardonForm Functions

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential AForm", 145, 137)
{
	this->_target = "Default";
	std::cout << "A default Presidential AForm named " << *this << " has been printed" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << *this << " has been shredded, it's the Form : " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & ref) : AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "PresidentialPardonAForm" << *this << " has been copied" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

// Function creation released by subject

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential AForm with name", 145,137)
{
	this->_target = target;
	std::cout << "Shrubbery AForm with name : " << *this << " has been printed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw (AForm::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << "In his great mercy, Sire Zafod Beeblebrock, president of the known and unknown universe, pardons you because he's a good man." << std::endl;
	}
}
