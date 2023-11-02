/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:43:22 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 16:03:54 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include <iostream>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <map>
# include <sstream>

class	User
{
	private:
		// User(User const &ref);					//no used
		// User &operator=(User const &ref);		//no used
		
		std::string				_nickname;
		std::string				_username;
		std::string				_realname;
		std::string				_hostname;
		std::string				_currentChannel;
		bool					_accepted;
		bool					_connected;
		int						_socket;
		struct sockaddr_in		_address;
		std::map<char, bool>	_modes;
		
	protected:
	public:

		std::string				_message;
		
	
		User(int socket, struct sockaddr_in address) : _socket(socket), _address(address)
		{
			_nickname = "";
			_username = "";
			_realname = "";
			_accepted = false;
			_connected = false;
		};
		~User(void) {};

		/// Setters ///

		void					setNickname(std::string nickname) { _nickname = nickname; };
		void					setUsername(std::string username) { _username = username; };
		void					setRealname(std::string realname) { _realname = realname; };
		void					setAccepted(bool accepted) { _accepted = accepted; };
		void					setConnected(bool connected) { _connected = connected; };
		void					setCurrentChannel(std::string channel) { _currentChannel = channel; };
		void					setMode(char mode, bool state) { _modes[mode] = state; };
		void					setHostname(std::string hostname) { _hostname = hostname; };
		
		/// Is ? ///
		bool					isAccepted(void) { return _accepted; };
		bool					isConnected(void) { return _connected; };
		bool					isMode(char mode);

		/// Getters ///
		
		std::string				getAddress(void) const { return inet_ntoa(_address.sin_addr); };
		std::map<char, bool>	getModes(void) const { return _modes; };
		std::string				getCurrentChannel(void) const { return _currentChannel; };
		std::string				getNickname(void) const { return _nickname; };
		std::string				getUsername(void) const { return _username; };
		std::string				getRealname(void) const { return _realname; };
		int						getSocket(void) const { return _socket; };

		bool		tryConnect(void);
		bool		sendRawMessage(std::string message);
		bool		sendMessage(std::string code, std::string message);
		bool		useMode(std::string mode);
		void		addMode(char mode) { setMode(mode, true); };
		void		removeMode(char mode) { setMode(mode, false); };

		std::string	to_string(bool isAnon);
		
};

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