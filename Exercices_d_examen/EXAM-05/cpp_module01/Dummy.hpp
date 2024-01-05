/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:38:39 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/09 17:02:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"
# include <iostream>

class	Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();

		virtual ATarget *clone() const;
};

#endif