/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/10 13:45:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:

		///// norme //////
		Character();	//
		//////////////////
		
		void	drop(AMateria * m);

		std::string	_name;
		AMateria	*_slot[4];
		AMateria	*_floor[4];
		int			_indexFloor;
	
	protected:


	
	public:
		
		////////////////// norme /////////////////////////////////
		Character(Character const & input);						//
		Character const & operator=(Character const & input);	//
		~Character(void);										//
		//////////////////////////////////////////////////////////
		
		Character(std::string const & name);
		std::string const & getName(void) const;
		void	equip(AMateria * m);
		void	unequip(int idx);
		void	use(int idx, ICharacter & target);

};

#endif
