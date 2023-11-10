/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:38:39 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/09 17:04:41 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dummy.hpp"


Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

ATarget *Dummy::clone() const
{
	return (new Dummy());
}
