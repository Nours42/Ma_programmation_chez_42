/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:12 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:27:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

/////////////////// SUMMARY //////////////////
// Getters Functions						//
// Setters Functions						//
// 		<< operator overload Function		//
// Canonical Form Functions					//
// Function creation released by subject	//
// Exceptions Functions						//
//////////////////////////////////////////////

// Getters Functions

const std::string	AForm::getName( void ) const
{
	return (this->_name);
}

int	AForm::getGradeToSign( void ) const
{
	return (this->_grade_to_sign);
}

int	AForm::getGradeToExecute( void ) const
{
	return (this->_grade_to_execute);
}

bool	AForm::getSigned( void ) const
{
	return (this->_signed);
}


// Setters Functions

void	AForm::setSigned( const bool new_value)
{
	std::cout << *this << " signed value was set to " << new_value << std::endl;
	this->_signed = new_value;
}

// 		<< operator overload Function

std::ostream & operator<<( std::ostream & o, AForm const & ref)
{
	o << ref.getName() << std::endl << "with a grade to sign : " << ref.getGradeToSign() << std::endl << "with a grade to execute : " << ref.getGradeToExecute() << std::endl << "with signed value equal to : " << ref.getSigned() << " (0 for not signed, 1 for signed)";
	return (o);
}

// canonical AForm Functions

AForm::AForm() : _name("Default"), _grade_to_sign(150), _grade_to_execute(150), _signed(0)
{
	std::cout << "A default AForm named " << *this << " has been printed" << std::endl;
}

AForm::~AForm()
{
	std::cout << *this << " has been shredded" << std::endl;
}

AForm::AForm(AForm const & ref) : _name(ref.getName()), _grade_to_sign(ref.getGradeToSign()), _grade_to_execute(ref.getGradeToExecute()), _signed(ref.getSigned())
{
	std::cout << *this << " has been copied" << std::endl;
}

AForm & AForm::operator=(AForm const & ref)
{
	this->_signed = ref.getSigned();
	return (*this);
}

// Function creation released by subject

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(0)
{
	if (_grade_to_sign > 150 || _grade_to_execute > 150) 
		throw (AForm::GradeTooLowException());
	else if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw (AForm::GradeTooHighException());
	else
	{
		std::cout << *this << " has been printed\n" << std::endl;
	}
}

void	AForm::be_signed(Bureaucrat & ref)
{
	int	grade = ref.getGrade();

	if (grade > _grade_to_sign)
	{
		throw (AForm::GradeTooLowExceptionToSigned());
		return;
	}
	_signed = true;
	std::cout << *this << " has been signed by bureaucrat " << ref.getName() << std::endl;
}

// Exceptions functions

const char*	AForm::Exception::what() const throw()
{
	return ("AFormException");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade > 150!");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade < 1!");
};

const char*	AForm::GradeTooLowExceptionToSigned::what() const throw()
{
	return ("\n\"You haven't the grade to signed this !!!!\"");
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form");
};
