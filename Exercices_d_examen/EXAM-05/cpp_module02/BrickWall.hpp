/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:32:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/10 11:47:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include <iostream>
# include "ATarget.hpp"

class BrickWall : public ATarget
{
	private:
		
		BrickWall(BrickWall const &ref);
		BrickWall &operator=(BrickWall const &ref);
	public:
		BrickWall();
		~BrickWall();

		virtual ATarget *clone() const;
};

#endif