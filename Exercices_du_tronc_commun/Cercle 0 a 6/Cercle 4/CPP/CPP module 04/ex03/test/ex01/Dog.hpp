/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:46:04 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 15:57:01 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_H
# define DOG_H
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{

public:

	Dog(void);
	Dog(Dog const & input);
	Dog const & operator=(Dog const & input);
	virtual	~Dog(void);

	virtual void	makeSound(void) const;
	void			setIdea(unsigned int index, std::string idea) const;
	std::string		getIdea(unsigned int index) const;

protected:


private:

	Brain * _myBrain;

};

#endif