/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/08 21:43:37 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

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

		/// Function creation released by subject ///

		Bureaucrat(std::string name, int grade);

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