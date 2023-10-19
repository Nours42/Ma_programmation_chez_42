/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/19 14:01:58 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

btcValues::btcValues() {}

btcValues::~btcValues() {}

btcValues &btcValues::operator=(btcValues &ref)
{
	this->_bvl = ref.getBtcList();
	return (*this);
}

std::map<int*, int> btcValues::getBtcList()
{
	return (this->_bvl);
}

btcValues::btcValues(btcValues &ref)
{	*this = ref; }

void	btcValues::_convertValuesToYMDV(std::string strIn)
{
	size_t		pos;
	std::string	strTemp;
	const char	*charTemp;

	strTemp = strIn.substr(0,4);
	charTemp = strTemp.c_str();
	this->_year = atoi(charTemp);
	strTemp = strIn.substr(6,2);
	charTemp = strTemp.c_str();
	this->_month = atoi(charTemp);
	strTemp = strIn.substr(9,2);
	charTemp = strTemp.c_str();
	this->_day = atoi(charTemp);
	pos = strIn.find(",");
	pos++;
	strTemp = strIn.substr(pos);
	charTemp = strTemp.c_str();
	this->_value = atoi(charTemp);
}


void	btcValues::openValuesList()
{
	int temp[3];
	std::ifstream	bvl("./cpp_09/data.csv");
	if (!bvl.is_open())
	{
		std::cout << "Coulnd't open the values file" << std::endl;
		return ;
	}
	else
	{
		std::string	line_read;
		while (getline(bvl, line_read))
		{
			_convertValuesToYMDV(line_read);
			temp[0] = this->_year;
			temp[1] = this->_month;
			temp[2] = this->_day;
			this->_bvl.insert(_bvl::value_type([temp], this->_value));
		}
		std::cout << "values file find and open with success" << std::endl;
		std::map<int*, int>::iterator it;
		it = _bvl.begin();
		while (++it!=_bvl.end())
		{
			std::cout << "at the " it->first[0] << "-" << it->first[1] << "-" << it->first[2] << ", the bitcoin have the value of " << it->second << ";" << std::endl;
		}
	}
	bvl.close();
}

void	btcValues::openInstructionsList(char **argv)
{
	std::ifstream	BitcoinExchangeList(argv[1]);
	if (!BitcoinExchangeList.is_open())
	{
		std::cout << "Coulnd't open the instruction file" << std::endl;
		return ;
	}
	else
	{
		std::cout << "input file find and open with success" << std::endl;
	}
	BitcoinExchangeList.close();
}

void	btcValues::doTheJob(char **argv)
{
	openValuesList();
	openInstructionsList(argv);
	// stocker les dates en tableau;
	// lire les instructions ligne a ligne;
		// verifier date
		// verifier montant
		// application ou rejet
}