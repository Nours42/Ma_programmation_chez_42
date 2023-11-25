/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelManager.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:15:05 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:15:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNELMANAGER_HPP
#define CHANNELMANAGER_HPP

#include <iostream>
#include <map>
#include "Channel.hpp"

class ChannelManager
{
	private:
		std::map<std::string, Channel*> _channels;

	public:
		ChannelManager(void) {}
		~ChannelManager(void) {}

		Channel*	add(std::string name, std::string topic)
		{
			Channel* chan = new Channel(name, topic);
			_channels[name] = chan;
			return chan;
		}

		bool	contains(std::string name)
		{
			return _channels.count(name) == 1;
		}

		bool	join(std::string name, User* user)
		{
			if (!this->contains(name))
				return false;
			return _channels[name]->join(user);
		}

		bool	leave(std::string name, User* user)
		{
			if (!this->contains(name))
				return false;
			return _channels[name]->leave(user);
		}

		Channel*	get(std::string name)
		{
			if (!this->contains(name))
				return NULL;
			return _channels[name];
		}

		void	remove(std::string name)
		{
			delete	_channels[name];
			_channels[name] = NULL;
		}

		std::map<std::string, Channel*> getChannels(void) const { return _channels; }
};

#endif
