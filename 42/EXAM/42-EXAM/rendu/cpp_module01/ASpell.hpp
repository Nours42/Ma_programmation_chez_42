/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:46 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

class ASpell
{
	private:

		
	
	protected:

		std::string	_name;
		std::string _effects;

	public:

		~ASpell();
		ASpell();
		ASpell(ASpell const &ref);
		ASpell &operator=(ASpell const &ref);
		
		//// setter ////

		//// getter ////

		std::string	&getName() const;
		std::string	&getEffects() const;

		//// other ////

		ASpell(std::string name, std::string effects);
		virtual Spell *clone() const = 0;

};
