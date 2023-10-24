/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/11 09:47:10 by sdestann         ###   ########.fr       */
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

		const std::string	getName( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExecute ( void ) const;
		bool				getSigned( void ) const;

		////////////////// Setters //////////////////

		void				setSigned (const bool new_value);

		/////////////// canonical form //////////////

		AForm();
		virtual ~AForm();
		AForm(AForm const & ref);
		AForm & operator=(AForm const & ref);

		/// Function creation released by subject ///

		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		void	be_signed(Bureaucrat & ref);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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

		class UnsignedFormException : public AForm :: Exception
		{
			public:
				virtual const char* what() const throw();
 		};

};

std::ostream & operator<<(std::ostream & o, AForm const & ref);

#endif