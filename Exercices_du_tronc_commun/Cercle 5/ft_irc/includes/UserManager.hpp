/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:31:45 by nours42           #+#    #+#             */
/*   Updated: 2023/10/29 18:55:47 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERMANAGER_HPP
# define USERMANAGER_HPP

# include "Server.hpp"
# include "User.hpp"

class	UserManager
{
	private:
	
		UserManager(UserManager const &ref);				// no used
		UserManager &operator=(UserManager const &ref);		// no used
		
		std::map<int, User*> _users;

	protected:
	public:
	
		UserManager(void) {};
		~UserManager(void) { _users.clear(); };
		
		std::map<int, User*>	getUsers(void) { return (_users); };
		void 	addUser(User *user);
		
};

#endif