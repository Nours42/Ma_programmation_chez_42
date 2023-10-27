/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:12 by nours42           #+#    #+#             */
/*   Updated: 2023/10/11 09:48:40 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/////////////////// SUMMARY //////////////////
// increment / decrement grade Functions	//
// Getters Functions						//
// Setters Functions						//
// 		<< operator overload Fuctnion		//
// canonical form Functions					//
// Function creation released by subject	//
// Exceptions Functions						//
//////////////////////////////////////////////

// increment / decrement grade Functions

void	Bureaucrat::incrementGrade( void )
{
	std::cout << "Incrementing bureaucrat " << _name << "'s grade " << _grade << " by 1 \n";
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	std::cout << "Decrementing bureaucrat " << _name << "'s grade " << _grade << " by 1 \n";
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

// Getters Functions

const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	std::cout << "Bureaucrat " << this->_name << " have a grade : " << this->_grade << " " << std::endl;
	return (this->_grade);
}

// Setters Functions

void	Bureaucrat::setGrade( const int new_grade)
{
	this->_grade = new_grade;
	std::cout << "Bureaucrat " << this->_name << "'s grade was set to " << new_grade << " " << std::endl;
}

		// << operator overload
		
std::ostream & operator<<( std::ostream & o, Bureaucrat const & ref)
{
	o << "Bureaucrat " << ref.getName() << " has a grade " << ref.getGrade() << " " << std::endl;
	return (o);
}

// canonical form Functions

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "A default Bureaucrat has been trained\n" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has been fired\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const & ref) : _name(ref.getName() + "_copyref")
{
	this->_grade = ref.getGrade();
	std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has been constructed by copyref\n";
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)
{
	this->_grade = ref.getGrade();
	return (*this);
}

// Function creation released by subject

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade = grade;
		std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has been engaged\n";
	}
}

void	Bureaucrat::signForm(AForm & ref)
{
	try
	{
		ref.be_signed(*this);
		std::cout << "Bureaucrat " << this->_name << " with a grade " << this->_grade << " succesfully signs " << ref << std::endl;
	}
	catch (AForm::Exception &e)
	{
		std::cout << "Bureaucrat " << this->_name << " with a grade " << this->_grade << " cannot sign " << ref << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " sucesfully executed " << form << std::endl;
	}
	catch (AForm::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

// Exceptions functions

const char*	Bureaucrat::Exception::what() const throw()
{
	return ("BureaucratException\n");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade > 150!\n");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade < 1!\n");
};
