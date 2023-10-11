/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/11 08:23:41 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class	Form;

class   Bureaucrat
{
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
		Bureaucrat & operator=(const Bureaucrat & rhs);

		/// Function or parameters released by subject ///

		Bureaucrat(std::string name, int grade);

		// ex01
		
		void	signForm(Form & ref);

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

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif