/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:46:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 09:46:27 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_H
# define DOG_H
# include <iostream>
# include "Animal.hpp"

class	Dog : public Animal
{

public:

	Dog(void);
	Dog(Dog const & input);
	Dog const & operator=(Dog const & input);
	~Dog(void);

	virtual void	makeSound(void) const;

protected:


private:


};

#endif