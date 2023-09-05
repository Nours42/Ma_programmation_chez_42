/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:17:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/05 09:12:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	Harl;

	// Desactiver les messages aue vous ne voulez pas
	Harl.complain("debug");
	Harl.complain("info");
	Harl.complain("warning");
	Harl.complain("error");
	return (0);
}