/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:34:42 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:03 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERCOMMAND_HPP
#define USERCOMMAND_HPP

#include "Command.hpp"

class UserCommand : public Command
{
	public:
		UserCommand(void);
		~UserCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif
