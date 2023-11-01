/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NamesCommand.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:44:57 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:45:24 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESCOMMAND_HPP
# define NAMESCOMMAND_HPP

# include "Command.hpp"

class NamesCommand : public Command
{
	private :

		// NamesCommand(NamesCommand const &ref);				//no used
		// NamesCommand &operator=(NamesCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		NamesCommand(Server* server);
		~NamesCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif