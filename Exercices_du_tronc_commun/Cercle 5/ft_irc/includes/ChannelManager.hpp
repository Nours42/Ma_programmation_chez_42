/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelManager.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:14 by nours42           #+#    #+#             */
/*   Updated: 2023/10/28 18:55:09 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNELMANAGER_HPP
# define CHANNELMANAGER_HPP

# include "Ircserv.hpp"
# include "Channel.hpp"

class	ChannelManager
{
	private:
	protected:
	public:
		ChannelManager();
		~ChannelManager();
		ChannelManager(ChannelManager const &ref);
		ChannelManager &operator=(ChannelManager const &ref);

        void    getChannels(void) const;
};

#endif