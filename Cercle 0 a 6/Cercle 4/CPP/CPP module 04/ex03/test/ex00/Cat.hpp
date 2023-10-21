/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:44:25 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 09:45:51 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_H
# define CAT_H
# include <iostream>
# include "Animal.hpp"

class	Cat : public Animal
{

public:

	Cat(void);
	Cat(Cat const & input);
	Cat const & operator=(Cat const & input);
	~Cat(void);

	virtual void	makeSound(void) const;

protected:


private:


};

#endif