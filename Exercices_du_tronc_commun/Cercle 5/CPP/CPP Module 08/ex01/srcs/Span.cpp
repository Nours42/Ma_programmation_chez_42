/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/18 16:50:35 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iomanip>

Span::Span(unsigned int n_ints) : _n_ints(n_ints)
{
	_vector.reserve(n_ints);
	_n_contents = 0;
}

Span::~Span()
{

}

Span &Span::operator=(Span const &ref)
{
	this->_n_ints = ref._n_ints;
	this->_vector = ref._vector;
	this->_n_contents = ref._vector.size();
	return (*this);
}

Span::Span(Span const &ref) : _n_ints(ref._n_ints), _vector(ref._vector)
{
	_n_contents = ref._vector.size();
}

/////// Better ///////

Span::Span(int min, int max, int numb_of_ints)
{
	int	min_min;
	int	max_max;

	if (min > max)
	{
		min_min = max;
		max_max = min;
	}
	else
	{
		min_min = min;
		max_max = max;
	}
	_n_ints = std::abs((max - min) / numb_of_ints);
	_vector.reserve(_n_ints);
	while (min_min < max_max)
	{
		_vector.push_back(min_min);
		min_min += numb_of_ints;
	}
	_n_contents = _n_ints;
}

void	Span::addNumber(my_iter start, my_iter end)
{
	// Avoid the infinite loop
	if (end < start)
		return ;
	for (my_iter i = start; i != end; i++)
		addNumber(*i);
}

/////// getters ///////

unsigned int Span::getNInts(void) const
{
	return (_n_ints);
}

unsigned int Span::getNContents(void) const
{
	return (_n_contents);
}

std::vector<int> Span::getVector(void) const
{
	return (_vector);
}

/////// add number ///////

void Span::addNumber(int n)
{
	if (_vector.size() >= _n_ints || _n_contents >= _n_ints)
		throw(std::out_of_range("Cannot add any more elements"));
	_vector.push_back(n);
	_n_contents++;
}

/////// longuest span ///////

int	Span::longestSpan(void)
{
	if (_n_contents == 0 || _n_contents == 1)
		throw(std::out_of_range("Not enougth element to do this"));
	std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	
	return (*max - *min);
}

int	Span::shortestSpan(void)
{
	unsigned int		i;
	int					shortest_span;
	std::vector<int>	v;

	if (_n_contents == 0 || _n_contents == 1)
		throw(std::out_of_range("Not enougth element to do this"));
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	shortest_span = *max;
	v = _vector;
	std::sort(v.begin(), v.end());
	i = 0;
	while (i < v.size())
	{
		if (i && std::abs(v[i] - v[i - 1]) < shortest_span)
			shortest_span = std::abs(v[i] - v[i - 1]);
		i++;
	}
	return (shortest_span);
}

std::ostream &operator<<( std::ostream &o, Span const &ref)
{
	unsigned int i;

	i = 0;
	std::cout << "Span contents: ";
	while (i < ref.getNContents())
	{
		std::cout << (ref.getVector())[i] << " ";
		i++;
	}
	std::cout << std::endl;
	return (o);
}