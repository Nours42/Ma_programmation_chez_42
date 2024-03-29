/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:51:04 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/01 20:00:37 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook_main.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void Contact::ft_print(void) const
{
	std::cout << "First Name: " << this->_first_name << std::endl;
	std::cout << "Last Name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl;
}

void Contact::ft_set_values(std::string f, std::string l, std::string n, std::string ph, std::string d)
{
	_first_name = f;
	_last_name = l;
	_nickname = n;
	_phone_number = ph;
	_darkest_secret = d;
}

std::string	Contact::get_first_name() const
{
	return (_first_name);
}

std::string	Contact::get_last_name() const
{
	return (_last_name);
}

std::string	Contact::get_nickname() const
{
	return (_nickname);
}

std::string	Contact::get_phone_number() const
{
	return (_phone_number);
}

std::string	Contact::get_darkest_secret() const
{
	return (_darkest_secret);
}