/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:17:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/04 12:09:37 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

int main(void)
{
	Point P1; //constructeur par defaut va donner 0 / 0
	Point P2(Fixed(7.95f), Fixed(6.17f));
	Point P3(Fixed(3.00f), Fixed(3.00f));
	Point P4(Fixed(10.00f), Fixed(0.0f));
	Point P5(P2); //constructeur par copie
	Point P6(Fixed(0.0f), Fixed(10.0f));
	Point P7 = P6; //assignation du =
	Point P8(Fixed(-0.15f), Fixed(-0.78f));

	// triangle 1
	std::cout << "Triangle 1" << std::endl;
	std::cout << "Le point A se trouve au coordonnees X : " << P1.getX() << " et Y : " << P1.getY() << std::endl;
	std::cout << "Le point B se trouve au coordonnees X : " << P2.getX() << " et Y : " << P2.getY() << std::endl;
	std::cout << "Le point C se trouve au coordonnees X : " << P3.getX() << " et Y : " << P3.getY() << std::endl;
	std::cout << "Le point P se trouve au coordonnees X : " << P4.getX() << " et Y : " << P4.getY() << std::endl;
	std::cout << "BSP renvoie les valeurs : \n" << bsp(P1, P2, P3, P4) << std::endl;

	// triangle 2
	std::cout << "Triangle 2" << std::endl;
	std::cout << "Le point A se trouve au coordonnees X : " << P1.getX() << " et Y : " << P1.getY() << std::endl;
	std::cout << "Le point B se trouve au coordonnees X : " << P4.getX() << " et Y : " << P4.getY() << std::endl;
	std::cout << "Le point C se trouve au coordonnees X : " << P6.getX() << " et Y : " << P6.getY() << std::endl;
	std::cout << "Le point P se trouve au coordonnees X : " << P3.getX() << " et Y : " << P3.getY() << std::endl;
	std::cout << "BSP renvoie les valeurs : \n" << bsp(P1, P4, P6, P3) << std::endl;
	
	return (0);
}
