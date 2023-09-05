/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:32:07 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/05 09:12:03 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>

void	ft_replace(std::string *line, std::string to_r, std::string r_w)
{
	size_t	start_pos;

	while ((start_pos = (*line).find(to_r)) != std::string::npos)
	{
		(*line).erase(start_pos, to_r.length());
		(*line).insert(start_pos, r_w);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4 || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Program arguments error" << std::endl;
		return (-1);
	}
	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cout << "Coulnd't open the input file" << std::endl;
		return (-1);
	}
	std::string	file_name = (std::string)argv[1] + ".replace";
	std::ofstream	ofs(file_name.c_str());
	if (!ofs.is_open())
	{
		std::cout << "Coulnd't open the output file" << std::endl;
		return (-1);
	}
	std::string	line_read;
	std::string	to_replace = argv[2];
	std::string	replace_with = argv[3];
	while (getline(ifs, line_read))
	{
		ft_replace(&line_read, to_replace, replace_with);
		if (!std::cin.eof())
			ofs << line_read << std::endl;
	}
	ofs.close();
	ifs.close();
	return (0);
}