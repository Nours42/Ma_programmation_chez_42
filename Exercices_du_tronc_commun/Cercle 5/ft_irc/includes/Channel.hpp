/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:43:22 by nours42           #+#    #+#             */
/*   Updated: 2023/10/31 12:28:12 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "Server.hpp"

class	Channel
{
	private:
		
		std::string							_name;
		std::string							_password;
		std::string							_topic;
		std::multimap<char, std::string>	_modes;
		std::vector<User*>					_banList;
		std::vector<User*>					_creator;
		std::vector<User*>					_excepList;
		std::vector<User*>					_inviteList;
		std::vector<User*>					_users;
		std::vector<User*>					_operators;
		std::vector<User*>					_moderates;
		std::size_t							_limit;


	protected:
	public:
		Channel(std::string name, std::string topic);
		~Channel();
		// Channel(Channel const &ref);
		// Channel &operator=(Channel const &ref);

		int					contains(User* user);
		int					contains(std::string name);

		/// ACTIONS ///

		bool				kick(User* sender, User *target, std::string arg);
		void				rawBroadcast(std::string message, User* sender);
		
		/// GETTERS ///

		std::string			getName(void) const { return _name; };

		/// LISTS ///
		
		std::vector<User*>					getBanList(void) const { return (_banList); }
		void								addBanList(User *user);
		bool 								isBanList(User *user) const;
		void								deleteBanList(User *user);
		void								addExcepList(User *user);
		void								deleteExcepList(User *user);
		bool								isExcepList(User *user) const;
		std::vector<User*>					getExcepList(void) const { return (_excepList); }
		std::vector<User*>					getInviteList(void) const { return (_inviteList); }
		void								addInviteList(User *user);
		void								deleteInviteList(User *user);
		bool 								isInviteList(User *user) const;
		bool 								isModerate(User *user) const;
		
		/// USERS ///
		User*								getUser(std::string name);
		std::vector<User*>					getUsers(void) const { return _users; }

		/// CREATORS ///
		void								setCreator(User *user);
		bool								isCreator(User *user) const;

		/// OPERATORS ///
		void								addOperator(User *user);
		bool								isOperator(User *user) const;
		void								deleteOperator(User *user);

		/// LIMITS ///

		void 								setLimit(std::string limit);
		void								unsetLimit(void) { _limit = -1; };
		std::size_t							getLimit(void) const { return (_limit); };
		bool								isFull(void) const;
		bool								checkLimit(std::string limit);

		/// MODERATES ///
		void								addModerate(User *user);
		void								deleteModerate(User *user);

		/// MODES ///

		void								deleteMode(char mode, std::string params);
		std::multimap<char, std::string>	getModes(void) const { return (_modes); };
		bool 								isSetMode(char mode, std::string params) const;
		bool								setMode(std::string mode, std::string params);

		/// PASSWORDS ///

		void 								setPassword(std::string pass) { _password = pass ;};
		void								unsetPassword(void) { _password = ""; };
		std::string							getPassword(void) const { return (_password); };
		bool								isPassword(std::string pass) const;

		/// TOPICS ///

		void								setTopic(std::string new_topic) { this->_topic = new_topic; };
		std::string							getTopic(void) const { return _topic; };

};

#endif