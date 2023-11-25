/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:54 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/22 13:19:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _USER_HPP_
#define _USER_HPP_

#include "ft_irc.hpp"

class User
{
	public:
		int			fd;
		int			conStep;
		std::string	username;
		std::string	nickname;
		std::string	realname;

		User(int & fd);
		~User();

		bool	operator==(User & user);
		bool	operator!=(User & user);
};

#endif
