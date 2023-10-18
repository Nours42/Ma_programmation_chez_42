/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:57:58 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/16 14:25:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template< typename T>
class Array
{
	private:

		T				*_t;
		unsigned int	_n;

	protected :



	public:

		////// Canonical Form ///////

		Array()
		{
			_n = 0;
			_t = new T[1];
			_t[0] = 0;
		}

		Array( unsigned int n ) : _n(n)
		{
			_t = new T[n];
		}
		
		Array(Array const & ref) : _n(ref.size())
		{
			unsigned int	i;
			T				*ref_t;

			i = 0;
			ref_t = ref.getT();
			_t = new T[_n];
			while (i < _n)
			{
				_t[i] = ref_t[i];
				i++;
			}
		}

		~Array()
		{
			delete [] this->_t;
		}

		Array &operator=(Array const &ref)
		{
			unsigned int	i;
			T				*ref_t;

			i = 0;
			ref_t = ref.getT();
			this->_n = ref.size();
			// au cas ou il en existe deja un on supprime
			delete [] this->_t;
			// puis on cree
			this->_t = new T[_n];
			while (i < _n)
			{
				_t[i] = ref_t[i];
				i++;
			}
			return (*this);
		}

		// [] operator
		T	&operator[](int i)
		{
			if (i < 0 || i >= static_cast<int>(this->_n))
			{
				throw (std::exception());
			}
			else
				return (*(_t + i));
		}
		
		// Getters:
		T 				*getT( void ) const
		{
			return (_t);
		}
		unsigned int	size( void ) const
		{
			return (_n);
		}
	
};

template< typename T >
std::ostream & operator<<(std::ostream & o, Array< T > const & ref)
{
	unsigned int	i;

	i = 0;
	while (i < ref.size())
	{
		std::cout << "T[" << i << "] : " << (ref.getT())[i] << std::endl;
		i++;
	}
	return (o);
}

#endif