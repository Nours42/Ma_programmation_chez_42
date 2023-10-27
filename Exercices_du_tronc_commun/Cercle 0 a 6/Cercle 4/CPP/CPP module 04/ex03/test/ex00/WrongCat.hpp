/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:55:09 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 09:55:28 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_H
# define WRONGCAT_H
# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{

public:

	WrongCat(void);
	WrongCat(WrongCat const & input);
	WrongCat const & operator=(WrongCat const & input);
	~WrongCat(void);

	virtual void	makeSound(void) const;

protected:


private:


};

#endif