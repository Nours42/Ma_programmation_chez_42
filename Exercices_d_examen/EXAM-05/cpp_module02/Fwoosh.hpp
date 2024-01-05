/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:31:24 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/10 11:47:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include "ASpell.hpp"


class Fwoosh : public ASpell
{
	private:
		
		Fwoosh(Fwoosh const &ref);
		Fwoosh &operator=(Fwoosh const &ref);
	public:
		Fwoosh();
		~Fwoosh();

		virtual ASpell *clone() const;
		
};

#endif