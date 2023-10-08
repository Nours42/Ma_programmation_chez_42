/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/08 22:13:34 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{

	// constructor with default parameters

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////// Engagement of a Default Bureaucrat /////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	try
	{
		Bureaucrat Bureaucrat;
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	// constructor with normal parameters

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////// Engagement of a Standard Bureaucrat ////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	try
	{
		Bureaucrat John("John", 111);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	// constructor with anormal parameters (negative grade)

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////// Engagement of a Anormal Bureaucrat ////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	try
	{
		Bureaucrat Bob("Bob", -1);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	// constructor with another anormal parameters (too high grade)

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////// Engagement of a anormal Bureaucrat ////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	try
	{
		Bureaucrat Martine("Martine", 123456);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	// test of increment grade

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////// increment Bureaucrat ////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	Bureaucrat Fred("Fred", 2);
	try
	{
		Fred.incrementGrade();
		Fred.getGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	// test of decrement grade

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////// decrement Fred //////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	try
	{
		Fred.decrementGrade();
		Fred.getGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	// test of increment grade error

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////// increment Bureaucrat ////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	try
	{
		Fred.getGrade();
		Fred.incrementGrade();
		Fred.getGrade();
		Fred.incrementGrade();
		Fred.getGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	// test of decrement grade error

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////// increment Bureaucrat ////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	Fred.setGrade(150);
	try
	{
		Fred.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	// Destructors

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////////////////// YOU'RE ALL FIRED NOW ///////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////// ELON M. /////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

}