/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:29:53 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/01 16:45:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOPICCOMMAND_HPP
# define TOPICCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class TopicCommand : public Command
{
	private :

		TopicCommand(TopicCommand const &ref);					//no used
		TopicCommand &operator=(TopicCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		TopicCommand(Server* sever);
		~TopicCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif