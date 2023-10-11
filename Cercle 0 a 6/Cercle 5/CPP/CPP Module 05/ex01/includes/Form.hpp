/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/11 08:23:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class   Form
{
	public:

		////////////////// Getters //////////////////

		const std::string	getName( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExecute ( void ) const;
		bool				getSigned( void ) const;

		////////////////// Setters //////////////////

		void				setSigned (const bool new_value);

		/////////////// canonical form //////////////

		Form();
		virtual ~Form();
		Form(Form const & ref);
		Form & operator=(const Form & ref);

		/// Function creation released by subject ///

		Form(std::string name, int grade_to_sign, int grade_to_execute);
		void	be_signed(Bureaucrat & ref);

		///////////////// Exceptions ////////////////

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowExceptionToSigned : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade_to_sign;
		int					_grade_to_execute;
		bool				_signed;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif