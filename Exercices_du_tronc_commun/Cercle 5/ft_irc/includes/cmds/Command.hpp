/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:32:28 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:27 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <vector>
#include "Console.hpp"
#include "Utils.hpp"
#include "User.hpp"
#include "Message.hpp"

class Command
{
	public:
		virtual ~Command(void) {}
		virtual bool onCommand(User* sender, std::vector<std::string> args) = 0;
};

#endif
