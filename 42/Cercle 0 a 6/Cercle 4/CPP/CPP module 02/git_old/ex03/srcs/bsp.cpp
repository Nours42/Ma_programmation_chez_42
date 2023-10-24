/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:22:06 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/04 12:07:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Je commence par recuuperer les coordonnees des points a, b, c et p :

Fixed	*get_w1( Point const a, Point const b, Point const c, Point const p)
{
	Fixed Ax = a.getX();
	Fixed Ay = a.getY();
	Fixed Bx = b.getX();
	Fixed By = b.getY();
	Fixed Cx = c.getX();
	Fixed Cy = c.getY();
	Fixed Px = p.getX();
	Fixed Py = p.getY();

	// les formules mathematiaues viennent de la video : https://yt.artemislena.eu/watch?v=HYAgJN3x4GA
	// une fois fait je calcule W1 et ensuite W2
	
	// W1 est egal a 0 si P est sur A
	// W1 est egal a 1 si P est sur B
	// W2 est egal a 0 si p est sur A
	// W2 est egal a 1 si p est sur C
    //       \               /
    //        \             /
	// --------A-----------B---------------
	//          \         /
	//           \       /
	//            \     /
	//             \   /
	//              \ /
	//               C
	//              / \    //
	//             /   \   //

	// si p est en dehors du triangle cote oppose a B W1 est negatif
	// si p est en dehors du triangle cote oppose a C W2 est negatif
	// et enfin si p est en dehors du triangle cote oppose a A la somme de W1 et W2 est > 1

	Fixed	num = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
	std::cout << "Valeur de num : " << num << std::endl;
	Fixed	denum = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
	std::cout << "Valeur de denum : " << denum << std::endl;
	Fixed	f = num / denum;
	std::cout << "Valeur de w1 : " << f << std::endl;
	Fixed *w1 = new Fixed(f);

	return (w1);
}

Fixed	*get_w2( Fixed w1, Point const a, Point const b, Point const c, Point const p)
{
	Fixed Ay = a.getY();
	Fixed By = b.getY();
	Fixed Cy = c.getY();
	Fixed Py = p.getY();

	Fixed	num = Py - Ay - w1 * (By - Ay);
	std::cout << "Valeur de num2 : " << num << std::endl;
	Fixed	denum = Cy - Ay;
	std::cout << "Valeur de denum2 : " << denum << std::endl;
	Fixed *w2 = new Fixed(num / denum);
	std::cout << "Valeur de w2 : " << *w2 << std::endl;

	return (w2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed *w1 = get_w1(a, b, c, point);
	Fixed *w2 = get_w2(*w1, a, b, c, point);
	bool	ret = true;

	if (*w1 > 0 && *w2 > 0 && (*w1 + *w2) < 1)
		ret = true;
	else
		ret = false;
	delete w1;
	delete w2;
	return (ret);
}