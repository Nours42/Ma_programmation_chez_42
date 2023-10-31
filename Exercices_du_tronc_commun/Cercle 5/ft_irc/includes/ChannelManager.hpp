/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelManager.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:14 by nours42           #+#    #+#             */
/*   Updated: 2023/10/31 10:26:00 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNELMANAGER_HPP
# define CHANNELMANAGER_HPP

# include "Server.hpp"
# include "Channel.hpp"

class Channel;


class	ChannelManager
{
	private:

		ChannelManager(ChannelManager const &ref);				//no used
		ChannelManager &operator=(ChannelManager const &ref);	//no used

		std::map<std::string, Channel*> _channels;

	protected:
	public:

		ChannelManager(void) {};
		~ChannelManager(void) {};
		
        std::map<std::string, Channel*> getChannels(void) const { return _channels; }

		bool	contains(std::string name) { return _channels.count(name) == 1;	};

		Channel*	add(std::string name, std::string topic)
		{
			Channel* chan = new Channel(name, topic);
			_channels[name] = chan;
			return chan;
		}

		Channel*	get(std::string name)
		{
			if (!this->contains(name))
				return NULL;
			return _channels[name];
		}
};

#endif