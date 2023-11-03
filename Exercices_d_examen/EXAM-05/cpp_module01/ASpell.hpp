/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:08:57 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/03 05:59:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
#include "ATarget.hpp"
class ATarget;

class	ASpell
{
	private:
		
		std::string		name;
		std::string		effects;

	protected:
	public:
		ASpell();
		ASpell(std::string const &n, std::string const &e);
		virtual ~ASpell();
		ASpell(ASpell const & ref);
		ASpell & operator=(ASpell const & ref);

		std::string		const & getName() const;
		std::string		const & getEffects() const;
		void launch(ATarget const &ATarget_ref) const;
		virtual ASpell	*clone() const = 0;

};

#endif
