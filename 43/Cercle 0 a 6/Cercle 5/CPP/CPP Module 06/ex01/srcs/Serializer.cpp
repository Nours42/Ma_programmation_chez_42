/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/16 14:09:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const &ref)
{
	*this = ref;
}

Serializer& Serializer::operator=(Serializer const &ref)
{
	if (this != &ref) {}
	return (*this);
}

uintptr_t	Serializer::Serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::Deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}