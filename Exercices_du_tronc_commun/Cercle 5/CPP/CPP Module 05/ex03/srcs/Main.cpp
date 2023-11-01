/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/11 11:49:00 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotMyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{

	// constructor of two bureaucrats Bob and Sylvie, Sylvie is grade 1 Bob 101

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////// Engagement of Bureaucrats Bob & Sylvie ///////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	Bureaucrat	bob("Bob", 150);
	Bureaucrat	antoine("Antoine", 100);
	Bureaucrat	gerald("Gerald", 50);
	Bureaucrat	sylvie("Sylvie", 1);
	Bureaucrat & bob_ref = bob;
	Bureaucrat & antoine_ref = antoine;
	Bureaucrat & gerald_ref = gerald;
	Bureaucrat & sylvie_ref = sylvie;
	
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	// constructor of a Srubbery Form

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////// Construction of Shrubbery Form //////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	ShrubberyCreationForm	a("A27");
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	// And now we signed it

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////////////////// Sign it tests //////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	bob_ref.signForm(a);
	a.getSigned();

	antoine_ref.signForm(a);
	a.getSigned();
	
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////////////////// Execute it test //////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	bob_ref.executeForm(a);
	antoine_ref.executeForm(a);

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////// Construction of Robot Request Form //////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	RobotMyRequestForm	b("A28");
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	// And now we signed it

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////////////////// Sign it tests //////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	bob_ref.signForm(b);
	b.getSigned();

	antoine_ref.signForm(b);
	b.getSigned();

	gerald_ref.signForm(b);
	b.getSigned();
	
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////////////////// Execute it test //////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	bob_ref.executeForm(b);
	antoine_ref.executeForm(b);
	gerald_ref.executeForm(b);

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////// Construction of Presidential Pardon Form //////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	PresidentialPardonForm	c("A29");
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	// And now we signed it

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////////////////// Sign it tests //////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	bob_ref.signForm(c);
	c.getSigned();

	antoine_ref.signForm(c);
	c.getSigned();

	gerald_ref.signForm(c);
	c.getSigned();

	sylvie_ref.signForm(c);
	c.getSigned();
	
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////////////////// Execute it test //////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	bob_ref.executeForm(c);
	antoine_ref.executeForm(c);
	gerald_ref.executeForm(c);
	sylvie_ref.executeForm(c);

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////////////////// Intern do this test //////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	Intern someRandomIntern;
	AForm* someRandomForm;
	someRandomForm = someRandomIntern.makeForm("presidential pardon", "With my Love, Zaffod");
	sylvie_ref.signForm(*someRandomForm);
	someRandomForm->getSigned();
	gerald_ref.executeForm(*someRandomForm);
	delete someRandomForm;
	
	// Destructors

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////////////// YOU'RE ALL FIRED NOW ///////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////// ELON M. /////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

}