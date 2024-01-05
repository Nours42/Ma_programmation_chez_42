/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:31:24 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/10 11:47:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include "ASpell.hpp"


class Fireball : public ASpell
{
	private:
		
		Fireball(Fireball const &ref);
		Fireball &operator=(Fireball const &ref);
	public:
		Fireball();
		~Fireball();

		virtual ASpell *clone() const;
		
};

#endif