/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/24 15:45:58 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>

class ATarget
{
	private:

		
	
	protected:

		std::string	_type;

	public:

		~ATarget();
		ATarget();
		ATarget(ATarget const &ref);
		ATarget &operator=(ATarget const &ref);
		
		//// setter ////

		//// getter ////

		std::string	&getType() const;

		//// other ////

		ATarget(std::string type);
		virtual Spell *clone() const = 0;
		void	getHitBySpell(ASpell const &spell) const;

};
