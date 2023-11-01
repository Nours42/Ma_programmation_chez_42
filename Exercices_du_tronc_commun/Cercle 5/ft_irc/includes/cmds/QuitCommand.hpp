/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:49:31 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:49:48 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUITCOMMAND_HPP
# define QUITCOMMAND_HPP

# include "Command.hpp"
# include "Server.hpp"
# include "Channel.hpp"

class QuitCommand : public Command
{
	private :

		// QuitCommand(QuitCommand const &ref);				//no used
		// QuitCommand &operator=(QuitCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		QuitCommand(Server* server);
		~QuitCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif