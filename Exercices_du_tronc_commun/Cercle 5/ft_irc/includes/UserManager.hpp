/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:31:45 by nours42           #+#    #+#             */
/*   Updated: 2023/10/31 15:17:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERMANAGER_HPP
# define USERMANAGER_HPP

# include <iostream>
# include <map>
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

		User* findbyNickname(std::string nickname)
		{
			std::map<int, User*>::iterator begin = _users.begin();
			while(begin != _users.end())
			{
				if (begin->second != NULL && nickname == begin->second->getNickname())
					return begin->second;
				begin++;
			}
			return NULL;
		};
		
};

#endif