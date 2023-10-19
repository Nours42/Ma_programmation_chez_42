/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/19 14:50:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

btcValues::btcValues() {}

btcValues::~btcValues() {}

btcValues &btcValues::operator=(btcValues &ref)
{
	this->_bitcoinValueList = ref.getBtcList();
	return (*this);
}

std::map<std::vector<int>, float> btcValues::getBtcList()
{
	return (this->_bitcoinValueList);
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
	this->_value = atof(charTemp);
}


void	btcValues::openValuesList()
{
	int	i = 0;
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
			if (i == 0)
				i++;
			else
			{
				_convertValuesToYMDV(line_read);
				temp[0] = this->_year;
				temp[1] = this->_month;
				temp[2] = this->_day;
				this->_bitcoinValueList.insert(std::make_pair(std::vector<int>(temp, temp + 3), this->_value));
			}
		}
		std::cout << "Values file found and opened successfully" << std::endl;
		// std::map<std::vector<int>, int>::iterator it;
		// for (it = _bitcoinValueList.begin(); it != _bitcoinValueList.end(); ++it)
		// {
		// 	std::cout << "At the " << it->first[0] << "-" << it->first[1] << "-" << it->first[2] << ", the bitcoin has the value of " << it->second << ";" << std::endl;
		// }
	}
	bvl.close();
}

void	btcValues::_convertInstructsToYMDV(std::string strIn)
{
	size_t		pos;
	std::string	strTemp;
	const char	*charTemp;

	pos = strIn.find(" | ");
	if (pos == std::string::npos)
		std::cout << "erreur de date" << std::endl;
	else
	{
		strTemp = strIn.substr(0,4);
		charTemp = strTemp.c_str();
		try
		{
			this->_year = atoi(charTemp);
		}
		catch (btcValues::DateError &e)
		{
			std::cout << e.what() << std::endl;
			return ;
		}
		strTemp = strIn.substr(6,2);
		charTemp = strTemp.c_str();
		try
		{
			this->_month = atoi(charTemp);
		}
		catch (btcValues::DateError &e)
		{
			std::cout << e.what() << std::endl;
			return ;
		}
		strTemp = strIn.substr(9,2);
		charTemp = strTemp.c_str();
		try
		{
			this->_day = atoi(charTemp);
		}
		catch (btcValues::DateError &e)
		{
			std::cout << e.what() << std::endl;
			return ;
		}
		pos = strIn.find(" | ");
		strTemp = strIn.substr(pos);
		charTemp = strTemp.c_str();
		try
		{
			this->_value = atof(charTemp);
		}
		catch (btcValues::DateError &e)
		{
			std::cout << e.what() << std::endl;
			return ;
		}
	}
}

void	btcValues::openInstructionsList(char **argv)
{
	int i = 0;
	int	temp[3];
	std::ifstream	BitcoinExchangeList(argv[1]);
	if (!BitcoinExchangeList.is_open())
	{
		std::cout << "Coulnd't open the instruction file" << std::endl;
		return ;
	}
	else
	{
		std::string	line_read;
		while (getline(BitcoinExchangeList, line_read))
		{
			if (i == 0)
				i++;
			else
			{
				_convertInstructsToYMDV(line_read);
				temp[0] = this->_year;
				temp[1] = this->_month;
				temp[2] = this->_day;
				this->_instructionList.insert(std::make_pair(std::vector<int>(temp, temp + 3), this->_value));
			}
		}
		std::cout << "Values file found and opened successfully" << std::endl;
		std::map<std::vector<int>, float>::iterator it;
		for (it = _instructionList.begin(); it != _instructionList.end(); ++it)
		{
			std::cout << "At the " << it->first[0] << "-" << it->first[1] << "-" << it->first[2] << ", the bitcoin has the value of " << it->second << ";" << std::endl;
		}
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