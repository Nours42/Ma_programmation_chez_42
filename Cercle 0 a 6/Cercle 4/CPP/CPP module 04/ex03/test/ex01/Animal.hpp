/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:31:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 09:42:28 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>
# include "colors.h"

class	Animal
{

public:

	Animal(void);
	Animal(std::string type);
	Animal(Animal const & input);
	Animal const & operator=(Animal const & input);
	virtual ~Animal(void);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;

protected:

	std::string		_type;


private:


};

#endif