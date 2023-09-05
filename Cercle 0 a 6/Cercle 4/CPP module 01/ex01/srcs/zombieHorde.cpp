/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:16:30 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/02 18:24:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;

    i = 0;
    Zombie  *horde = new Zombie[N];
    while (i < N)
    {
        if (i /10 > 0)
            horde[i].set_name(name + " " + (char)(i /10 + 48) + char(i + 38));
        else
            horde[i].set_name(name + " " + (char)(i + 48));
        horde[i].announce();
        i++;
    }
    return (&(horde[0]));
}