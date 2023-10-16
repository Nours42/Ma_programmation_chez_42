/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/16 15:15:19 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

// Base::Base() {}

Base::~Base() {}

// Base::Base(Base const &ref)
// {
// 	*this = ref;
// }

// Base& Base::operator=(Base const &ref)
// {
// 	if (this != &ref) {}
// 	return (*this);
// }

Base	*generate(void)
{
	srand(time(NULL));
	int choose = std::rand() % 3;

	if (choose < 1)
		return (new A());
	else if (choose < 2)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
		std::cout << "i can't identify this" << std::endl;
}

void	identify(Base &p)
{
try
{
	A& a = dynamic_cast<A &>(p);
	(void)a;
	std::cout << "A" << std::endl;
}
catch (std::exception& e1)
{
	try
	{
		B& b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception& e2)
	{
		try
		{
			C& c = dynamic_cast<C &>(p);
			(void)c;
			std::cout << "C" << std::endl;
		}
			catch (std::exception& e3)
			{
				std::cerr << "Unknown type is neither A, B, or C" << std::endl;
			}
	}
}
}