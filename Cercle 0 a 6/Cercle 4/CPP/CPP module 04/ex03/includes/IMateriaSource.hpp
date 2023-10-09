/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/09 21:59:48 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class	AMateria;

class	IMateriaSource
{
	private:

	protected:

	public:
	
		virtual void	learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;

		////////////// canonical form ////////////////////////////
		IMateriaSource();										//
		virtual ~IMateriaSource();								//
		IMateriaSource(IMateriaSource & ref);					//
		IMateriaSource & operator=(const IMateriaSource & ref);	//
		//////////////////////////////////////////////////////////
};

#endif