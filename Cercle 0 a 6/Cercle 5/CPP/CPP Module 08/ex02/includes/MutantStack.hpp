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

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>
# include <vector>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		
	protected:
	public:

		/////// Canonical Form ///////

		// MutantStack();
		// ~MutantStack();
		// MutantStack(MutantStack const &ref);
		// MutantStack &operator=(MutantStack const &ref);

		typedef	T*	iterator;
		typedef	T const *	const_iterator;

		iterator begin()
		{
			std::vector<T>	v;
			T				top;
			iterator		ret;
			int				n;
			
			n = 0;
			while (!this->empty())
			{
				top = this->top();
				v.push_back(top);
				this->pop();
				n++;
			}
			this->push(v[n - 1]);
			n--;
			ret = &(this->top());
			while (n--)
				this->push(v[n]);
			return (ret);
		}

		iterator end()
		{
			return (&this->top() + 1);
		}
};

#endif