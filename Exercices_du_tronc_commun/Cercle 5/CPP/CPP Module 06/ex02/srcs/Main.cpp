/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/16 14:57:56 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "../includes/Base.hpp"

int	main(void)
{
	Base *base = generate();
	// Base *base2 = NULL;

	// success :
	
	identify(base);
	identify(*base);

	// fails :

	// identify(base2);
	// identify(*base2);

	delete base;

	return (0);
}