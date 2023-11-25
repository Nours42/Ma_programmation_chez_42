/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:30 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/25 20:47:45 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHANNEL_HPP_
# define _CHANNEL_HPP_

#include "ft_irc.hpp"

class Channel
{
	public:
		int						maxUsers;
		int						nbUsers;
		std::string				name;
		std::string				topic;
		std::string				lastTopicUpdateWhen;
		std::string				lastTopicUpdateWho;
		std::string				mode;
		std::string				password;
		std::vector<User *>		users;
		std::vector<User *>		operators;
		std::vector<User *>		invitedUsers;

		bool	isModeI() const;
		bool	isModeT() const;
		bool	isModeK() const;
		bool	isModeL() const;

		bool	isInChannel(User *user);
		bool	isOpInChannel(User *user);
		bool	isBestOp(User * user, std::vector<User *>::iterator iterator);
		bool	isInvited(User *user);
		void	printChannelUsers(std::string logType) const;
		void	channelSendLoop(std::string message, int & sFd, Server * server, int sendToHim);
		int		deleteChannelUser(std::vector<User *>::iterator iterator, Server * server);
		int		deleteChannelUser(User * user, Server * server);
		int		deleteChannelUser(User * user, Server * server, int noErase);
		void	allocNewOp(Server * server);
		std::vector<User *>::iterator	getUserByNick(std::string nickname);
		void	opUser(User * user, std::vector<User *>::iterator, Server * server);
		void	deOpUser(User * user, std::vector<User *>::iterator iterator, Server * server);

		Channel(std::string name);
		~Channel();
};

#endif
