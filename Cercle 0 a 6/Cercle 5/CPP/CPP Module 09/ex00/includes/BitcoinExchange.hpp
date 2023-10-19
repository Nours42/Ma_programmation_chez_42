/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/19 14:47:04 by sdestann         ###   ########.fr       */
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
# include <vector>

class	btcValues
{
	private:
		
		std::map<std::vector<int>, float>	_bitcoinValueList;
		std::map<std::vector<int>, float> _instructionList;
		void				_convertValuesToYMDV(std::string strIn);
		void				_convertInstructsToYMDV(std::string strIn);
		int					_year;
		int					_month;
		int					_day;
		float				_value;
		
	protected:
	public:
		/////// Canonical Form ///////
		btcValues();
		~btcValues();
		btcValues &operator=(btcValues &ref);
		btcValues(btcValues &ref);

		/////// getter ///////
		std::map<std::vector<int>, float>	getBtcList(void);

		/////// Fucntions ///////
		void	doTheJob(char **argv);
		void	openValuesList(void);
		void	openInstructionsList(char **argv);
		void	verificationDate(int*);
		void	verificationAmount(int);


		/////// Exceptions ///////
		class	DateError : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Erreur de Date"; }
		};

		class	ValueError : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Erreur de Valeur"; }
		};
};


#endif