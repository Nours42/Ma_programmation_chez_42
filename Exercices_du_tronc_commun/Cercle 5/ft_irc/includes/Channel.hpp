/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:43:22 by nours42           #+#    #+#             */
/*   Updated: 2023/10/28 18:55:14 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "Ircserv.hpp"

class	Channel
{
	private:
	protected:
	public:
		Channel();
		~Channel();
		Channel(Channel const &ref);
		Channel &operator=(Channel const &ref);
};

#endif