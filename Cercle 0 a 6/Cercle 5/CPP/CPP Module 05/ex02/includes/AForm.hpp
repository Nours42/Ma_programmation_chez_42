/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:35:08 by sdestann         ###   ########.fr       */
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
	public:

		////////////////// Getters //////////////////

		const std::string	getName( void ) const = 0;
		int					getGradeToSign( void ) const = 0;
		int					getGradeToExecute ( void ) const = 0;
		bool				getSigned( void ) const = 0;

		////////////////// Setters //////////////////

		void				setSigned (const bool new_value) = 0;

		/////////////// canonical form //////////////

		AForm();
		virtual ~AForm();
		AForm(AForm const & ref);
		AForm & operator=(const AForm & ref);

		/// Function creation released by subject ///

		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		void	be_signed(Bureaucrat & ref) = 0;

		///////////////// Exceptions ////////////////

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public AForm::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public AForm::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowExceptionToSigned : public AForm::Exception
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

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif