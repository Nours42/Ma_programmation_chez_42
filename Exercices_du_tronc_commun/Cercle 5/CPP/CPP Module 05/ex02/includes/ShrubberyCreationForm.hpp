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
# include <iomanip>
# include <fstream>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class   ShrubberyCreationForm : public AForm
{
	private:

		std::string	_target;
	
	protected:




	public:

		////////////////// Getters //////////////////

		std::string	getTarget( void ) const;

		////////////////// Setters //////////////////

		/////////////// canonical form //////////////

		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & ref);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & ref);

		/// Function creation released by subject ///

		ShrubberyCreationForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
};

#endif