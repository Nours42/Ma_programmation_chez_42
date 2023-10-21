/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:31:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 16:24:53 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AAnimal_H
# define AAnimal_H
# include <iostream>
# include "colors.h"

class	AAnimal
{

public:

	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(AAnimal const & input);
	AAnimal const & operator=(AAnimal const & input);
	virtual ~AAnimal(void);

	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;

protected:

	std::string		_type;


private:


};

#endif