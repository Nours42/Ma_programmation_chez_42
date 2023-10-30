/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelManager.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:14 by nours42           #+#    #+#             */
/*   Updated: 2023/10/30 16:06:42 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNELMANAGER_HPP
# define CHANNELMANAGER_HPP

# include "Server.hpp"
# include "Channel.hpp"

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
};

#endif