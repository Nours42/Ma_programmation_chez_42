/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotMyRequestForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:12 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:27:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotMyRequestForm.hpp"

/////////////////// SUMMARY //////////////////
// Getters Functions						//
// Canonical Form Functions					//
// Function creation released by subject	//
// Exceptions Functions						//
//////////////////////////////////////////////

// Getters Functions

std::string	RobotMyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

// canonical RobotMyRequestForm Functions

RobotMyRequestForm::RobotMyRequestForm() : AForm("Default Robot AForm", 72, 45)
{
	this->_target = "Default";
	std::cout << "A default Robot AForm named " << *this << " has been printed" << std::endl;
}

RobotMyRequestForm::~RobotMyRequestForm()
{
	std::cout << *this << " has been shredded, it's the Form : " << _target << std::endl;
}

RobotMyRequestForm::RobotMyRequestForm(RobotMyRequestForm const & ref) : AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "RobotMyRequestAForm" << *this << " has been copied" << std::endl;
}

RobotMyRequestForm & RobotMyRequestForm::operator=(RobotMyRequestForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

// Function creation released by subject

RobotMyRequestForm::RobotMyRequestForm(std::string target) : AForm("Robot AForm with name", 72,45)
{
	this->_target = target;
	std::cout << "Robot AForm with name : " << *this << " has been printed" << std::endl;
}

const char* RobotMyRequestForm::FailureException::what() const throw()
{
	return ("Robotomy failure");
}

// RANDOM TO IMPLEMENT
void RobotMyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw (AForm::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());	
	int success = std::rand() % 4;
		std::cout << "< intensive drilling noises >\n";
	if (success >= 1)
	{
		std::cout << this->_target << " has been robotomized" << std::endl;
	}
	else
		throw (RobotMyRequestForm::FailureException());
}
