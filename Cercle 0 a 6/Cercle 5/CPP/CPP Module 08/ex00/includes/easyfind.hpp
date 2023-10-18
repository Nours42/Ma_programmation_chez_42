/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/18 12:22:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <iterator>

template< typename T >
int easyfind(T const &t, int n)
{
	typename T::const_iterator end = t.end();
	typename T::const_iterator it = std::find(t.begin(), end, n);

	return (it == end ? throw(std::out_of_range("Element not found in given range")) : *it);
}


#endif