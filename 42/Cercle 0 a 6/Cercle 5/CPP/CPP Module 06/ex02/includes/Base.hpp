/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:57:58 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/16 14:25:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

class	Base
{
	private:
		// Base();
		// Base(Base const &ref);
		// Base &operator=(Base const &ref);

	protected:

	public:
	////// canonical form //////
	
	virtual ~Base();
};

	class A : public Base {};
	class B : public Base {};
	class C : public Base {};

	////// Implement the following functions //////

	// Base * generate(void);
	// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
	// to use anything you like for the random choice implementation.

	Base	*generate( void );

	// void identify(Base* p);
	// It prints the actual type of the object pointed to by p: "A", "B" or "C".

	void	identify(Base* p);

	// void identify(Base& p);
	// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
	// inside this function is forbidden.

	void	identify(Base &p);

#endif