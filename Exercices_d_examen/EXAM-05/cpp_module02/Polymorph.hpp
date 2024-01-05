/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:31:24 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/10 11:47:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>
# include "ASpell.hpp"


class Polymorph : public ASpell
{
	private:
		
		Polymorph(Polymorph const &ref);
		Polymorph &operator=(Polymorph const &ref);
	public:
		Polymorph();
		~Polymorph();

		virtual ASpell *clone() const;
		
};

#endif