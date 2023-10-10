/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/10 20:40:41 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class   AForm
{
	private:
		const std::string	_name;
		int					_grade_to_sign;
		int					_grade_to_execute;
		bool				_signed;

	protected:


	
	public:

		////////////////// Getters //////////////////

		virtual const std::string	getName( void ) const = 0;
		virtual int					getGradeToSign( void ) const = 0;
		virtual int					getGradeToExecute ( void ) const = 0;
		virtual bool				getSigned( void ) const = 0;

		////////////////// Setters //////////////////

		virtual void				setSigned (const bool new_value) = 0;

		/////////////// canonical form //////////////

		AForm();
		virtual ~AForm();
		AForm(AForm const & ref);
		AForm & operator=(const AForm & ref);

		/// Function creation released by subject ///

		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		virtual void	be_signed(Bureaucrat & ref) = 0;
		virtual void	execute(Bureaucrat const & executor) const = 0;

		///////////////// Exceptions ////////////////

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw() = 0;
		};

		class GradeTooLowException : public AForm::Exception
		{
			public:
				virtual const char* what() const throw() = 0;
		};

		class GradeTooHighException : public AForm::Exception
		{
			public:
				virtual const char* what() const throw() = 0;
		};

		class GradeTooLowExceptionToSigned : public AForm::Exception
		{
			public:
				virtual const char* what() const throw() = 0;
		};

		class unsignedFormException : public AForm :: Exception
		{
			public:
				virtual const char* what() const throw() = 0;
 		}

	
};

std::ostream & operator<<(std::ostream & o, AForm const & ref);

#endif