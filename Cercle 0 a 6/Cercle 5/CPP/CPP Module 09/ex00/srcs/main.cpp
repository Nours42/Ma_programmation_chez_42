/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/23 13:35:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

void checkArgs(int argc)
{
	if (argc != 2)
		throw (std::runtime_error("Usage: ./btc [file]"));
}

std::fstream * openFileStream(char * filename)
{
	std::string path = filename;
	struct stat filecheck;
	if (stat(filename, &filecheck) != 0)
		throw (std::runtime_error(path + ": invalid file"));
	if ((filecheck.st_mode & S_IFREG) == 0)
		throw (std::runtime_error(path + ": is a directory"));
	if ((filecheck.st_mode & S_IXUSR) != 0)
		throw (std::runtime_error(path + ": is an executable"));
	std::fstream * fs = new std::fstream();
	fs->open(filename, std::fstream::in);
	if (fs->fail())
	{
		delete fs;
		throw (std::runtime_error(path + ": could not open file"));
	}
	return (fs);
}

bool isStringEmpty(std::string string)
{
	if (string.empty())
		return (true);
	std::string::iterator it = string.begin();
	while (it != string.end())
	{
		if (!isblank(*it))
			return (false);
		it++;
	}
	return (true);
}

bool shouldLineBeEvaluated(char * line)
{
	std::string lineStr(line);
	if (isStringEmpty(line) == true || lineStr == "date | value")
		return (false);
	return (true);
}

std::string * splitString(std::string string, std::string sep)
{
	std::string * split = new std::string[2];
	size_t delim = string.find(sep, 0);
	if (delim == std::string::npos)
	{
		delete [] (split);
		throw (std::out_of_range(string + ": invalid input"));
	}
	split[0] = string.substr(0, delim);
	split[1] = string.substr(delim + sep.length(), std::string::npos);
	return (split);
}

void evaluateInput(BitcoinExchange & btc, std::fstream & fs)
{
	int i = 0;
	while (!fs.eof())
	{
		char			line[100];
		std::string		*split = NULL;

		fs.getline(line, 100);
		if (fs.eof() || shouldLineBeEvaluated(line) == false)
		{
			i++;
			continue;
		}
		std::cout << std::endl << CYAN "Input: " << line << RESET << std::endl;
		try
		{
			split = splitString(line, "|");
			btc.outputExchangeValueOnDate(split[0], split[1]);
		}
		catch (std::exception & e)
		{
			std::cerr << "Error: " << e.what() << " (line " << i << ": " << line << ")" << std::endl;
		}
		delete [] (split);
		i++;
	}
}

int main(int argc, char **argv)
{
	BitcoinExchange * btc = NULL;
	std::fstream * fs = NULL;
	try
	{
		checkArgs(argc);
		fs = openFileStream(argv[1]);
		btc = new BitcoinExchange();
		evaluateInput(*btc, *fs);
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		delete btc;
		delete fs;
		return (1);
	}
	delete btc;
	delete fs;
	return (0);
}