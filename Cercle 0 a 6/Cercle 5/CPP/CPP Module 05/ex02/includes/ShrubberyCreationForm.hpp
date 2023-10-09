/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:35:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Bureaucrat;

class   ShrubberyCreationForm : public Form
{
	public:

		////////////////// Getters //////////////////

		std::string	getTarget( void ) const;

		////////////////// Setters //////////////////

		/////////////// canonical form //////////////

		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & ref);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & ref);

		/// Function creation released by subject ///

		ShrubberyCreationForm(std::string target);
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

#endif