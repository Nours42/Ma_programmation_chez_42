/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:45 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 11:11:49 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODECOMMAND_HPP
# define MODECOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../User.hpp"

class ModeCommand : public Command
{
	private :

		// ModeCommand(ModeCommand const &ref);				//no used
		// ModeCommand &operator=(ModeCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		ModeCommand(Server* sever);
		~ModeCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif