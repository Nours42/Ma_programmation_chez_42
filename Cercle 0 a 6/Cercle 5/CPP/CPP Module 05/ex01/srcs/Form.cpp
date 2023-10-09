/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:12 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:27:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/////////////////// SUMMARY //////////////////
// Getters Functions						//
// Setters Functions						//
// 		<< operator overload Function		//
// Canonical form Functions					//
// Function creation released by subject	//
// Exceptions Functions						//
//////////////////////////////////////////////

// Getters Functions

const std::string	Form::getName( void ) const
{
	return (this->_name);
}

int	Form::getGradeToSign( void ) const
{
	return (this->_grade_to_sign);
}

int	Form::getGradeToExecute( void ) const
{
	return (this->_grade_to_execute);
}

bool	Form::getSigned( void ) const
{
	return (this->_signed);
}


// Setters Functions

void	Form::setSigned( const bool new_value)
{
	std::cout << *this << " signed value was set to " << new_value << std::endl;
	this->_signed = new_value;
}

// 		<< operator overload Function

std::ostream & operator<<( std::ostream & o, Form const & rhs)
{
	o << "Form " << rhs.getName() << std::endl << "with a grade to sign : " << rhs.getGradeToSign() << std::endl << "with a grade to execute : " << rhs.getGradeToExecute() << std::endl << "with signed value equal to : " << rhs.getSigned() << " (0 for not signed, 1 for signed)";
	return (o);
}

// canonical form Functions

Form::Form() : _name("Default"), _grade_to_sign(150), _grade_to_execute(150), _signed(0)
{
	std::cout << "A default Form named " << *this << " has been printed" << std::endl;
}

Form::~Form()
{
	std::cout << *this << " has been shredded" << std::endl;
}

Form::Form(Form const & ref) : _name(ref.getName()), _grade_to_sign(ref.getGradeToSign()), _grade_to_execute(ref.getGradeToExecute()), _signed(ref.getSigned())
{
	std::cout << "Form " << *this << " has been copied" << std::endl;
}

Form & Form::operator=(Form const & ref)
{
	this->_signed = ref.getSigned();
	return (*this);
}

// Function creation released by subject

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(0)
{
	if (_grade_to_sign > 150 || _grade_to_execute > 150) 
		throw (Form::GradeTooLowException());
	else if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	else
	{
		std::cout << *this << " has been printed\n" << std::endl;
	}
}

void	Form::be_signed(Bureaucrat & ref)
{
	int	grade = ref.getGrade();

	if (grade > _grade_to_sign)
	{
		throw (Form::GradeTooLowExceptionToSigned());
		return;
	}
	_signed = true;
	std::cout << *this << " has been signed by bureaucrat " << ref.getName() << std::endl;
}

// Exceptions functions

const char*	Form::Exception::what() const throw()
{
	return ("FormException");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade > 150!");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade < 1!");
};

const char*	Form::GradeTooLowExceptionToSigned::what() const throw()
{
	return ("\n\"You haven't the grade to signed this !!!!\"");
}
