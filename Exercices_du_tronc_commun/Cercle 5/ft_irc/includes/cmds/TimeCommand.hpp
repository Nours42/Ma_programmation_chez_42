/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:50:02 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:50:26 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMERCOMMAND_HPP
# define TIMERCOMMAND_HPP

# include "Command.hpp"
# include "Server.hpp"
# include "Channel.hpp"

class TimeCommand : public Command
{
	private :

		// TimeCommand(TimeCommand const &ref);				//no used
		// TimeCommand &operator=(TimeCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		TimeCommand(Server* server);
		~TimeCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif