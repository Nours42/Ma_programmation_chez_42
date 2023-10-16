/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:57:58 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/16 14:25:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h> //pour les uintptr_t
# include "Data.hpp"

class	Serializer
{
	private:

	protected:

	public:
	////// canonical form //////
	Serializer();
	~Serializer();
	Serializer(Serializer const &ref);
	Serializer &operator=(Serializer const &ref);

	static uintptr_t	Serialize(Data* ptr);
	static Data*		Deserialize(uintptr_t raw);
};


#endif