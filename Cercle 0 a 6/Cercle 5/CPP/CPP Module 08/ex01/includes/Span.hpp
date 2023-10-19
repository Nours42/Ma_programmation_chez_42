/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/18 16:48:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <iterator>
# include <vector>
# include <cmath>
# include <cstdlib>

typedef std::vector<int>::iterator my_iter;

class	Span
{
	private:
	
		unsigned int		_n_ints;
		unsigned int		_n_contents;
		std::vector<int>	_vector;

//j'utilise vector car le tableau doit etre extensible de 0 membre a unigned int max membres

	protected:

	public:
	/////// Canonical Form ///////
	Span(unsigned int n_ints);
	~Span();
	Span &operator=(Span const &ref);
	Span(Span const &ref);

	/////// Better creator form ///////

	Span(int min, int max, int numb_of_ints);

	/////// Better add number /////////

	void	addNumber(my_iter start, my_iter end);

	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();

	class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	/////// getter ///////

	unsigned int		getNInts(void) const;
	unsigned int		getNContents(void) const;
	std::vector<int>	getVector(void) const;
};

std::ostream & operator<<( std::ostream & o, Span const & rhs);

#endif