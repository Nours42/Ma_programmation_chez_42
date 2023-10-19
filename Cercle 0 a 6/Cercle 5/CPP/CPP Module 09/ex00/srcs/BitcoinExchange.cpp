/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/19 15:50:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

amount::amount()
{
	_date = "";
	_value = 0.0f;
}

amount::amount(std::string s, int v)
{
	_date = s;
	_value = v;
}

amount	&amount::operator=(amount const &a)
{
	_date = a.getdate();
	_value = a.getvalue();
	return *this;
}

amount::amount(amount const &ref) : _date(ref._date), _value(ref._value)
{}


void	amount::wrongdateformat(std::string input)
{
	_date = "Error: bad input -> " + std::string(input.begin(), input.begin() + input.find(','));
	_value = -1;
}

float amount::getvalue() const
{
	return (_value);
}

std::string	amount::getdate() const
{
	return (_date);
}

void	amount::setdate(std::string d)
{
	_date = d;
}

void	amount::setvalue(float i)
{
	_value = i;
}

amount amount::getamount(std::string text)
{
	amount			ret;
	int 			month, day;
	std::string		date;
	const char		*temp;
	float			value;

	if (text[10] != ',')
	{
		ret.wrongdateformat(text);
		return (ret);
	}
	temp = (std::string(&text[5], &text[7]).c_str());
	month = atoi(temp);
	temp = (std::string(&text[8], &text[10]).c_str());
	day = atoi(temp);
	if (month < 0 || month > 12 || day < 0 || day > 31)
	{
		ret.wrongdateformat(text);
		return (ret);
	}
	date = std::string(text.begin(), text.begin() + text.find(','));
	if (ret.getdate() == "")
		ret.setdate(date);
	temp = std::string(text.begin() + text.find(',') + 1, text.end()).c_str();
	value = atof(temp);
	if (value < 0 || value > 1000)
	{
		if (value > 1000)
			ret.setdate("Error: too large a number.");
		else
			ret.setdate("Error: not a positive number.");
		ret.setvalue(-1);
	}
	if (ret.getvalue() != -1)
		ret.setvalue(value);
	return (ret);
}

std::queue<amount>	amount::getqueue(char *f)
{
	std::queue<amount>	ret;
	std::ifstream file(f);
	std::string line;

	if (file.is_open())
	{
		std::getline(file, line);
		while (std::getline(file, line))
		{
			ret.push(getamount(line));
		}
		file.close();
	}
	else
	{
		std::cerr << "Unable to open file" << std::endl;
	}
	return (ret);
}