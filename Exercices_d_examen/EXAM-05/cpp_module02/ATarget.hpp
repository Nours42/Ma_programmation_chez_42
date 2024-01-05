/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:53:06 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/09 15:58:52 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string	type;

	public:
		ATarget();
		ATarget(std::string const &type);
		virtual ~ATarget();
		ATarget(ATarget const &ref);
		ATarget &operator=(ATarget const &ref);

		std::string	const &getType(void) const;
		void	getHitBySpell(ASpell const &refAtarget) const;

		virtual ATarget *clone() const = 0;
};

#endif