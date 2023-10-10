/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:12 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:27:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

/////////////////// SUMMARY //////////////////
// Getters Functions						//
// Canonical Form Functions					//
// Function creation released by subject	//
// Exceptions Functions						//
//////////////////////////////////////////////

// Getters Functions

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

// canonical ShrubberyCreationForm Functions

ShrubberyCreationForm::ShrubberyCreationForm() : _name("ShrubberyCreationForm"), _grade_to_sign(145), _grade_to_execute(137)
{
	this->_target = "Default";
	std::cout << "A default ShrubberyCreationForm named " << *this << " has been printed" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << *this << " has been shredded" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & ref) : Form(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "ShrubberyCreationForm" << *this << " has been copied" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

// Function creation released by subject

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145,137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm " << *this << " has been printed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	tree = 
" 		# #### ####				\n"
"	### \/#|### |/####			\n"
"	##\/#/ \||/##/_/##/_#		\n"
"	###  \/###|/ \/ # ###		\n"
"##_\_#\_\## | #/###_/_####		\n"
"## #### # \ #| /  #### ##/##	\n"
"__#_--###`  |{,###---###-~		\n"
"			\ }{				\n"
"			}}{					\n"
"			}}{					\n"
"		    {{}					\n"
"	, -=-~{ .-^- _				\n";

	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
	{
		std::ofstream	ofs(this->_target);
		if (!ofs.is_open())
		{
			std::cout << "Coulnd't open the output file" << std::endl;
			return ;
		}
		ofs << tree;
	}
}
