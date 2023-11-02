/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:43:22 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 16:02:26 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Channel
{
	private:
		
		std::string							_name;
		std::string							_topic;
		std::map<char, std::string>			_modes;
		std::vector<User*>					_users;
		std::vector<User*>					_moderators;

	protected:
	public:
		Channel(std::string name, std::string topic);
		~Channel();
		// Channel(Channel const &ref);
		// Channel &operator=(Channel const &ref);

		/// ACTIONS ///

		bool						join(User* user);
		bool						leave(User* user);
		bool						kick(User* sender, User *target, std::string arg);
		
		/// GETTERS ///

		std::string					getName(void) const { return _name; };
		std::string					getTopic(void) const { return _topic; };
		std::map<char, std::string>	getModes(void) const { return (_modes); };
		std::vector<User*>			getUsers(void) const { return (_users); };
		std::vector<User*>			getModerators(void) const { return (_moderators); };

		/// MODERATORS ///
		void						addModerator(User *user);
		void						deleteModerator(User *user);
		bool 						isModerator(User *user) const;
		std::string					listModerators(void) const;

		/// MODES ///

		void						addMode(char mode, std::string params);
		void						deleteMode(char mode, std::string params);
		bool 						isSetMode(char mode, std::string params) const;
		bool						setMode(std::string mode, std::string params);


		/// TOPICS ///

		void						addTopic(char Topic, std::string params);
		void						deleteTopic(char Topic, std::string params);
		void						setTopic(std::string new_topic);

};

class	ChannelManager
{
	private:

		

		std::map<std::string, Channel*> _channels;

	protected:
	public:

		// ChannelManager(void) {};
		// ~ChannelManager(void) {};
		// ChannelManager(ChannelManager const &ref);				//no used
		// ChannelManager &operator=(ChannelManager const &ref);	//no used

		Channel*	add(std::string name, std::string topic)
		{
			Channel* chan = new Channel(name, topic);
			_channels[name] = chan;
			return chan;
		}

		bool	join(std::string name, User* user)
		{
			if (!this->contains(name))
				return false;
			return _channels[name]->join(user);
		}

		bool	leave(std::string name, User* user)
		{
			if (!this->contains(name))
				return false;
			return _channels[name]->leave(user);
		}

		Channel*	get(std::string name)
		{
			if (!this->contains(name))
				return NULL;
			return _channels[name];
		}

		void	remove(std::string name)
		{
			delete	_channels[name];
			_channels[name] = NULL;
		}

		std::map<std::string, Channel*> getChannels(void) const { return _channels; }
};

#endif