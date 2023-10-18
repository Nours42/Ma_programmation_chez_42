/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/18 11:05:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int			iarr[4] = {0, 1, 2, 3};
	char		carr[5] = "abcd";
	double		darr[4] = {12.1, 13.2, 14.3, 15.4};
	float		farr[4] = {0.1f, 2.3f, 4.5f, 6.7f};
	std::string	sarr[4] = {"un", "deux", "trois", "quatre"};

	ft_tests(carr, 5, "CHAR");
	ft_tests(darr, 4, "DOUBLE");
	ft_tests(farr, 4, "FLOAT");
	ft_tests(iarr, 4, "INT");
	ft_tests(sarr, 4, "STRING");

	return (0);
}