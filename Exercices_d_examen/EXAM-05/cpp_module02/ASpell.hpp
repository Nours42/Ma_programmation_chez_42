/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:53:06 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/10 11:43:49 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string	_name;
		std::string	_effects;
	public:
		ASpell();
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();
		ASpell(ASpell const &ref);
		ASpell &operator=(ASpell const &ref);

		std::string	const &getName() const;
		std::string const &getEffects() const;

		void launch(ATarget const &refAtarget) const;

		virtual ASpell *clone() const = 0;
};

#endif