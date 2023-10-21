/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:55:28 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 16:30:32 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_H
# define BRAIN_H
# include <iostream>
# include "colors.h"

class	Brain
{


public:

	Brain(void);
	Brain(Brain const & input);
	Brain const & operator=(Brain const & input);
	~Brain(void);

	void			setIdea(unsigned int index, std::string idea);
	std::string		getIdea(unsigned int index) const;

protected:

private:

	static unsigned int const	_MaxIdeas = 100;
	std::string					_ideas[_MaxIdeas];

};

#endif