/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/23 13:39:16 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <stdexcept>
# include <string>
# include <cctype>
# include <map>
# include <string.h>
# include <algorithm>
# include <limits>

# include <cstdio>
# include <cstdlib>
# include <sys/stat.h>
# include <sys/types.h>
# include <ctime>

# include <fstream>
# include <sstream>

//////// colors ////////

# define RESET	"\e[0m"

# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"
# define WHITE	"\e[37m"

std::string		*splitString(std::string string, std::string sep);
bool			isStringEmpty(std::string string);

class BitcoinExchange
{
	private:

		std::map<time_t, double>	_exchangeRate;

		void				_fillExchangeRateTable(void);
		void				_fillExchangeRateEntry(std::string line);
		void				_addExchangeRateEntry(time_t date, double value);
		time_t				_getClosestDateInTable(time_t date);
		double				_getExchangeRateOnDate(time_t date);

		time_t				_getEpochFromDateString(std::string &date) const;
		int					_getYearFromString(std::string &dateStr) const;
		int					_getMonthFromString(std::string &dateStr) const;
		int 				_getDayFromString(std::string &dateStr) const;
		std::string const	_getDateFromEpoch(time_t epochDate) const;
		double				_getValueFromString(std::string &valueStr) const;

		void				_checkInputStrings(std::string &dateStr, std::string &valueStr) const;
		void				_checkValueString(std::string &string) const;
		void				_checkDateString(std::string &string) const;
		void				_checkDayString(std::string &string) const;

		void				_printClosestExchangeRate(time_t date);

	protected:
	public:

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange &ref);
		BitcoinExchange &operator=(BitcoinExchange &ref);
		void 	outputExchangeValueOnDate(std::string &dateStr, std::string &valueStr);
		double	getExchangeValueOnDate(std::string &dateStr, std::string &valueStr);

		
};

#endif