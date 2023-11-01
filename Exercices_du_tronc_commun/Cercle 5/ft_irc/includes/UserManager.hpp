/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:31:45 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 11:55:16 by sdestann         ###   ########.fr       */
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

		bool contains(std::string nickname)
		{
			return this->findbyNickname(nickname) != NULL;
		}

		bool contains(int socket) { return _users.count(socket) == 1; }

		User* findBySocket(int socket)
		{
			std::cout << "UserManager - findBySocket : " << socket << std::endl;
			if (!this->contains(socket))
			{
				std::cout << "socket inconnu" << std::endl;
				for (int i = 0; _users[i]; i++)
				{
					std::cout << "users connu : " << i << " de valeur " << _users[i] << std::endl;
				}
				return NULL;
			}
			return _users[socket];
		};

		void add(User* user)
		{
			_users.insert(std::pair<int, User*>(user->getSocket(), user));
		}
		
		void remove(int socket)
		{
			_users.erase(socket);
		}
};

#endif