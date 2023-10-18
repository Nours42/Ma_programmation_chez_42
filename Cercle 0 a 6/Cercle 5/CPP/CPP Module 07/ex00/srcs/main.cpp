/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/18 10:27:09 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"
#include <iomanip>

int main( void )
{
	char		ca;
	char		cb;
	double		da;
	double		db;
	float		fa;
	float		fb;
	int			ia;
	int			ib;
	std::string	sa;
	std::string	sb;
	

	ca = 'a';
	cb = 'b';
	da = 42.4;
	db = -42.4;
	fa = 42.42f;
	fb = -42.42f;
	ia = 42;
	ib = -42;
	sa = "l'ecole 42 c'est fantastique !";
	sb = "je prefere l'ecole 21";

	ft_test(ca, cb, "char");
	ft_test(da, db, "double");
	ft_test(fa, fb, "float");
	ft_test(ia, ib, "int");
	ft_test(sa, sb, "string");

	return (0);
}