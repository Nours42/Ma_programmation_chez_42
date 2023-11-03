/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:38:39 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/03 06:06:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dummy.hpp"


Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

ATarget *Dummy::clone() const
{
	return(new Dummy());
}
