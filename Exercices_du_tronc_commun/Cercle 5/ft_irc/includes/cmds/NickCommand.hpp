/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:45:43 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:45:59 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICKCOMMAND_HPP
# define NICKCOMMAND_HPP

# include "Command.hpp"

class NickCommand : public Command
{
	private :

		// NickCommand(NickCommand const &ref);				//no used
		// NickCommand &operator=(NickCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		NickCommand(Server* server);
		~NickCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif