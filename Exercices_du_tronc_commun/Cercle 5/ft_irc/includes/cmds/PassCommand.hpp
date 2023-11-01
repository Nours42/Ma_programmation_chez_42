/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:47:43 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:47:56 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSCOMMAND_HPP
# define PASSCOMMAND_HPP

# include "Command.hpp"
# include "Server.hpp"
# include "Channel.hpp"

class PassCommand : public Command
{
	private :

		// PassCommand(PassCommand const &ref);				//no used
		// PassCommand &operator=(PassCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		PassCommand(Server* server);
		~PassCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif