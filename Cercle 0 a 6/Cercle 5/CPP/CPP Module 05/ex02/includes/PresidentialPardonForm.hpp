/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:10:08 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 15:35:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class AForm;

class   PresidentialPardonForm : public AForm
{
	private:

		std::string	_target;
	
	protected:




	public:

		////////////////// Getters //////////////////

		std::string	getTarget( void ) const;

		////////////////// Setters //////////////////

		/////////////// canonical form //////////////

		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & ref);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & ref);

		/// Function creation released by subject ///

		PresidentialPardonForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
};

#endif