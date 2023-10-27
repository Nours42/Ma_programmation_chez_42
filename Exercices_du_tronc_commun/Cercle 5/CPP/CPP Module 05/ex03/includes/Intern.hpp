/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/11 11:11:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotMyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	AForm;

class   Intern
{
	private:

	
	
	protected:


	
	public:

		/////////////// canonical form //////////////

		Intern();
		~Intern();
		Intern(Intern const & ref);
		Intern & operator=(Intern const & ref);

		/// Function or parameters released by subject ///

		AForm	*makeForm(std::string nameOfAForm, std::string target);

		///////////////// Exceptions ////////////////

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif