/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:20:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{

	// constructor of two bureaucrats Bob and Sylvie, Sylvie is grade 1 Bob 101

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////// Engagement of Bureaucrats Bob & Sylvie ///////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	Bureaucrat	bob("Bob", 101);
	Bureaucrat	sylvie("Sylvie", 1);
	Bureaucrat & bob_ref = bob;
	Bureaucrat & sylvie_ref = sylvie;
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	// constructor of two forms

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////// Construction of two forms A38 et A39 ///////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	Form	a("A38", 5, 7);
	Form	b("A39", 148, 149);
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	// constructor with anormal parameters (from with negative grade)

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////// Create an anormal form (negative value) //////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	try
	{
		Form	c("A40", -3, -1425);
	}
	catch (Form::Exception &e)
	{
		std::cout << "Constructor Form failure because of \"" << e.what() << "\"" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	// constructor with anormal parameters (from with negative grade)

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////// Create an anormal form (too high value) //////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	try
	{
		Form	c("A41", 3021, 1425);
	}
	catch (Form::Exception &e)
	{
		std::cout << "Constructor Form failure because of " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	// And now we signed it

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////////////// Sign it tests : OK ////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	sylvie_ref.signForm(a);
	a.getSigned();
	a.setSigned(false);

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////////////// Sign it tests : KO ////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	bob_ref.signForm(a);
	a.getSigned();
	a.setSigned(false);
	bob_ref.signForm(b);
	b.getSigned();
	b.setSigned(false);

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	
	// Destructors

	std::cout << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////////////// YOU'RE ALL FIRED NOW ///////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////// ELON M. /////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

}