/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:18:09 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/04 11:51:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "../includes/Fixed.hpp"

// CANONIC FORM
// Class containing at least:
// 1) Constructor default
// 2) Copy constructor
// 3) '=' Operator overload
// 4) Destructor (virtual!)

class	Point
{
	public:
		Point();
		~Point();
		
		Point(Point const & p);
		Point(float const x, float const y);
		Point(Fixed const x, Fixed const y);
		Point & operator=( Point & rhs);
		void	setX(Fixed f);
		void	setY(Fixed f);
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

	private:
		Fixed	const x;
		Fixed	const y;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif