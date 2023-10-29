/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:43:22 by nours42           #+#    #+#             */
/*   Updated: 2023/10/29 19:05:31 by nours42          ###   ########.fr       */
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
		bool					_accepted;
		bool					_connected;
		
	protected:
	public:
	
		User(void) 
		{
			_nickname = "";
			_username = "";
			_realname = "";
			_accepted = false;
			_connected = false;
		};
		~User(void) {};
		void		setNickname(std::string nickname) { _nickname = nickname; }
		void		setUsername(std::string username) { _username = username; }
		void		setRealname(std::string realname) { _realname = realname; }
		void		setAccepted(bool accepted) { _accepted = accepted; };
		bool		isAccepted(void) { return _accepted; };
		void		setConnected(bool connected) { _connected = connected; };
		bool		isConnected(void) { return _connected; };

		bool		tryConnect(void)
		{
			if (isConnected() || !isAccepted() || getUsername().empty() || getNickname().empty())
				return (false);

			setConnected(true);
			std::cout << "Welcome to my IRC " << _username << " !" << std::endl;
			std::cout << _username << " has join IRC" << std::endl;
			return (true);
		};

		std::string	getNickname(void) const { return _nickname; };
		std::string	getUsername(void) const { return _username; };
		std::string	getRealname(void) const { return _realname; };
};

#endif