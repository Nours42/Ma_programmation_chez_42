/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:08:57 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/03 05:17:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
#include "ASpell.hpp"
class ASpell;

class	ATarget
{
	private:
		
		std::string		type;

	protected:
	public:
		ATarget();
		ATarget(std::string const &t);
		virtual ~ATarget();
		ATarget(ATarget const & ref);
		ATarget & operator=(ATarget const & ref);

		std::string	const	& getType() const;
		void	getHitBySpell(ASpell const & aspell_ref) const;
		virtual ATarget *clone() const = 0;

};

#endif
