/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:32:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/10 11:47:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include "ATarget.hpp"

class Dummy : public ATarget
{
	private:
		
		Dummy(Dummy const &ref);
		Dummy &operator=(Dummy const &ref);
	public:
		Dummy();
		~Dummy();

		virtual ATarget *clone() const;
};

#endif