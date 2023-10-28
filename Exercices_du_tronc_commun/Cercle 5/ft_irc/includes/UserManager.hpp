/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:31:45 by nours42           #+#    #+#             */
/*   Updated: 2023/10/28 18:54:59 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERMANAGER_HPP
# define USERMANAGER_HPP

# include "Ircserv.hpp"
# include "User.hpp"

class	UserManager
{
	private:
	protected:
	public:
		UserManager();
		~UserManager();
		UserManager(UserManager const &ref);
		UserManager &operator=(UserManager const &ref);

		void	getUsers(void) const;
};

#endif