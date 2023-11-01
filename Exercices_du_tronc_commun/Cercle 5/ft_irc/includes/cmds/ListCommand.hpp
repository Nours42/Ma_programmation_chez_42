/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:42:54 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:43:25 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTCOMMAND_HPP
# define LISTCOMMAND_HPP

# include "Command.hpp"
# include "Server.hpp"
# include "Channel.hpp"

class ListCommand : public Command
{
	private :

		// ListCommand(ListCommand const &ref);				//no used
		// ListCommand &operator=(ListCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		ListCommand(Server* server);
		~ListCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif