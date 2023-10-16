/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/16 14:26:13 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data() : info (0) {}

Data::Data(int imput) : info (imput) {}

Data::~Data() {}

Data::Data(Data const &ref)
{
	*this = ref;
}

Data& Data::operator=(Data const &ref)
{
	if (this != &ref)
	{
		this->info = ref.info;
	}
	return (*this);
}