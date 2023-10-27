/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/11 09:45:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class	AForm;

class   Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;
	
	protected:


	
	public:

		//////// increment / decrement grade ////////

		void				incrementGrade( void );
		void				decrementGrade( void );

		////////////////// Getters //////////////////

		const std::string	getName( void ) const;
		int					getGrade( void ) const;

		////////////////// Setters //////////////////

		void				setGrade (const int new_grade);

		/////////////// canonical form //////////////

		Bureaucrat();
		virtual ~Bureaucrat();
		Bureaucrat(Bureaucrat const & ref);
		Bureaucrat & operator=(const Bureaucrat & ref);

		/// Function or parameters released by subject ///

		Bureaucrat(std::string name, int grade);

		// ex01
		
		void	signForm(AForm & ref);
		void	executeForm(AForm const & form);

		///////////////// Exceptions ////////////////

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & ref);

#endif