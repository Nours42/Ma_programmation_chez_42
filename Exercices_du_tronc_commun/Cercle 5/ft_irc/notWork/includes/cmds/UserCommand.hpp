/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:18 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:17:19 by sdestann         ###   ########.fr       */
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
