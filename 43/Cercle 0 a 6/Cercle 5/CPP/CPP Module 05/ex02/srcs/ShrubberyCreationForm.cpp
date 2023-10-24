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

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery AForm", 145, 137)
{
	this->_target = "Default";
	std::cout << "A default Shrubbery AForm named " << *this << " has been printed" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << *this << " has been shredded, it's the Form : " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & ref) : AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "ShrubberyCreationAForm" << *this << " has been copied" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

// Function creation released by subject

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery AForm with name", 145,137)
{
	this->_target = target;
	std::cout << "Shrubbery AForm with name : " << *this << " has been printed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	tree = 
"      # #### ####              \n"
"     ## /#|### |/##            \n"
"    #/#/||/##/_/##/_#          \n"
"  ###  /###|/ / # ###          \n"
" ##__#_## | #/###_/_####       \n"
"## #### #  #| /  #### ##/#     \n"
"__#_--###`  |{,###---###-~     \n"
"           }}{                 \n"
"           }}{                 \n"
"           }}{                 \n"
"           }}{                 \n"
",,,,,,,,,-=-~{ .-^- _,,,,,,,,,,\n";

	if (this->getSigned() == false)
		throw (AForm::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else
	{
		std::string	file_name = (std::string)this->_target + "_shrubbery";
		std::ofstream	ofs(file_name.c_str());
		if (!ofs.is_open())
		{
			std::cout << "Coulnd't open the output file" << std::endl;
			return ;
		}
		ofs << tree;
	}
}
