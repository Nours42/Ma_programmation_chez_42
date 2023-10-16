/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/16 14:29:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int	main(void)
{
	Data data;
	
	data = Data(42);

	uintptr_t raw = Serializer::Serialize(&data);
	Data	*ptr = Serializer::Deserialize(raw);

	std::cout << "Raw pointer : " << &data << std::endl;
	std::cout << "Data pointer : " << ptr << std::endl;

	std::cout << "Data info:   " << data.info << std::endl;
	std::cout << "Ptr info:    " << ptr->info << std::endl;
}