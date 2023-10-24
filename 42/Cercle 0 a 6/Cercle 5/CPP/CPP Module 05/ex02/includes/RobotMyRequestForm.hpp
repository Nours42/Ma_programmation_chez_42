/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotMyRequestForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:35:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class AForm;

class   RobotMyRequestForm : public AForm
{
	private:

		std::string	_target;
	
	protected:




	public:

		////////////////// Getters //////////////////

		std::string	getTarget( void ) const;

		////////////////// Setters //////////////////

		/////////////// canonical form //////////////

		RobotMyRequestForm();
		~RobotMyRequestForm();
		RobotMyRequestForm(RobotMyRequestForm const & ref);
		RobotMyRequestForm & operator=(const RobotMyRequestForm & ref);

		/// Function creation released by subject ///

		RobotMyRequestForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
		class FailureException : public AForm::Exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif