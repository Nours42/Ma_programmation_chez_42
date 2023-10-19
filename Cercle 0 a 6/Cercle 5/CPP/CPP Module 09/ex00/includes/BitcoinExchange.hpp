/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/19 15:46:58 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <queue>
# include <string>
# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>

class amount
{
	private:

		std::string		_date;
		float			_value;

	protected:
	public:

		amount();
		amount(std::string s, int v);
		amount &operator=(amount const &ref);
		amount(amount const &ref);

		void				wrongdateformat(std::string input);
		float				getvalue() const;
		std::string			getdate() const;
		void				setdate(std::string d);
		void				setvalue(float i);
		amount 				getamount(std::string text);
		std::queue<amount>	getqueue(char *f);
};

#endif