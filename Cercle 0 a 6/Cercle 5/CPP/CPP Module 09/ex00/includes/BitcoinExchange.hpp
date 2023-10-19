/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/19 12:31:20 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <iomanip>
# include <string>

class	btcValues
{
	private:
		
		std::map<int*, int>	_bvl;
		void				_convertValuesToYMDV(std::string strIn);
		int					_year;
		int					_month;
		int					_day;
		int					_value;
		
		
	protected:
	public:
		/////// Canonical Form ///////
		btcValues();
		~btcValues();
		btcValues &operator=(btcValues &ref);
		btcValues(btcValues &ref);

		/////// getter ///////
		std::map<int*, int>	getBtcList(void);

		/////// Fucntions ///////
		void	doTheJob(char **argv);
		void	openValuesList(void);
		void	openInstructionsList(char **argv);
		void	verificationDate(int*);
		void	verificationAmount(int);


		/////// Exceptions ///////
		class	DateError : public std::exception
		{
			virtual const char* what() const throw() { return "Erreur de Date"; }
		};

		class	ValueError : public std::exception
		{
			virtual const char* what() const throw() { return "Erreur de Valeur"; }
		};
};


#endif