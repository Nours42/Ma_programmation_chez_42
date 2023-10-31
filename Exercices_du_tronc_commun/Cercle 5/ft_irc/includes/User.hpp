/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:43:22 by nours42           #+#    #+#             */
/*   Updated: 2023/10/31 12:21:22 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include "Server.hpp"

class	User
{
	private:
		User(User const &ref);					//no used
		User &operator=(User const &ref);		//no used
		
		std::string				_nickname;
		std::string				_username;
		std::string				_realname;
		std::string				_currentChannel;
		bool					_accepted;
		bool					_connected;
		int						_socket;
		struct sockaddr_in		_address;
		std::map<char, bool>	_modes;
		
	protected:
	public:
	
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

		void					setNickname(std::string nickname) { _nickname = nickname; }
		void					setUsername(std::string username) { _username = username; }
		void					setRealname(std::string realname) { _realname = realname; }
		void					setAccepted(bool accepted) { _accepted = accepted; };
		void					setConnected(bool connected) { _connected = connected; };
		void					setCurrentChannel(std::string channel) { _currentChannel = channel; };
		
		/// Is ? ///
		bool					isAccepted(void) { return _accepted; };
		bool					isConnected(void) { return _connected; };

		/// Getters ///
		
		std::map<char, bool>	getModes(void) const { return _modes; }
		std::string				getCurrentChannel(void) const { return _currentChannel; }
		std::string				getNickname(void) const { return _nickname; };
		std::string				getUsername(void) const { return _username; };
		std::string				getRealname(void) const { return _realname; };
		int						getSocket(void) const { return _socket; }

		bool		tryConnect(void);
		bool		sendRawMessage(std::string message);
		bool		sendMessage(std::string code, std::string message);
		bool		useMode(std::string mode);

		std::string	to_string(bool isAnon) const;
		
};

#endif