/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:20:11 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/25 20:48:38 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

void irc_join_cases(const std::string& message, User *user, Server *server) {
    int flag = 0;
    if (message[0] == '0') {
        std::vector<Channel *>::iterator it = server->channels.begin();
        std::vector<Channel *>::iterator ite = server->channels.end();
        while (it != ite) {
            if ((*it)->isInChannel(user) || (*it)->isOpInChannel(user)) {
                flag = 1;
                std::string channelName = (*it)->name;
                std::string rpl_part = ":" + user->nickname + " PART #" + channelName + " :Left all channels\r\n";
                (*it)->channelSendLoop(rpl_part, user->fd, server, 1);
                (*it)->nbUsers--;
                (*it)->deleteChannelUser(user, server, 0);
            }
            it++;
        }
        if (flag == 0) {
            std::string rpl_not_valid_name = ":127.0.0.1 476 " + user->nickname + " " + message + " :Invalid channel name\r\n";
            send(user->fd, rpl_not_valid_name.c_str(), rpl_not_valid_name.length(), 0);
            send_log(user->fd, rpl_not_valid_name, server);
        }
        server->checkChannel();
        return;
    } else {
        std::string rpl_not_valid_name = ":127.0.0.1 476 " + user->nickname + " " + message + " :Invalid channel name\r\n";
        send(user->fd, rpl_not_valid_name.c_str(), rpl_not_valid_name.length(), 0);
        send_log(user->fd, rpl_not_valid_name, server);
        return;
    }
}

void	join_rmInvit(Channel *channel, User *user)
{
	for (std::vector<User *>::iterator it = channel->invitedUsers.begin(); it != channel->invitedUsers.end(); ++it)
	{
		if ((*it)->fd == user->fd)
		{
			channel->invitedUsers.erase(it);
			return ;
		}
	}
}

std::string parse_join(std::string message, std::string &passwd) {
    size_t i = 0;
    while (i < message.length() && message[i] != ' ')
        ++i;

    passwd = (i + 1 < message.length()) ? message.substr(i + 1) : "";
    message.resize(i);
	std::cout << JOIN << " > Try to join channel " << message << RESET << std::endl;
	std::cout << JOIN << " > Channel password : " << passwd << RESET << std::endl;
	return message;
}

void irc_join(std::string message, User *user, Server *server) 
{
	std::string passwd;
	std::cout << COMMAND << "JOIN" << std::endl;
	if (message.empty())
    {
        std::string err_need_more_param = ":127.0.0.1 461 " + user->nickname + " JOIN :Not enough parameters\r\n";
        send(user->fd, err_need_more_param.c_str(), err_need_more_param.length(), 0);
        send_log(user->fd, err_need_more_param, server);
        return ;
    }
	std::stringstream ss(message);
	std::string token;
    std::getline(ss, token, ' ');
    if (token.empty())
        return;

    if (token[0] != '#')
		return irc_join_cases(token, user, server);
	token = token.substr(1);

    std::string line;
    std::getline(ss, line, '\n');
	
	for (std::vector<Channel *>::iterator it = server->channels.begin(); it != server->channels.end(); ++it)
	{
		if ((*it)->name == token)
		{
			if ((*it)->isModeI())
			{
				if (!(*it)->isInvited(user))
				{
					std::string rpl_not_invited = ":127.0.0.1 473 " + user->nickname + " #" + (*it)->name + " :Cannot join channel (+i)\r\n";
					send(user->fd, rpl_not_invited.c_str(), rpl_not_invited.length(), 0);
					send_log(user->fd, rpl_not_invited, server);
					return;
				}
			}
			if ((*it)->isModeL())
			{
				if ((*it)->nbUsers >= (*it)->maxUsers)
				{
					std::string rpl_channel_full = ":127.0.0.7 471 " + user->nickname + " #" + (*it)->name + " :Cannot join channel (+l)\r\n";
					send(user->fd, rpl_channel_full.c_str(), rpl_channel_full.length(), 0);
					send_log(user->fd, rpl_channel_full, server);
					return;
				}
			}
			if ((*it)->isModeK() && !(*it)->isInvited(user))
			{
				if ((*it)->password != passwd)
				{
					std::string rpl_wrong_passwd = ":127.0.0.1 475 " + user->nickname + " #" + (*it)->name + " :Cannot join channel (+k)\r\n";
					send(user->fd, rpl_wrong_passwd.c_str(), rpl_wrong_passwd.length(), 0);
					send_log(user->fd, rpl_wrong_passwd, server);
					return;
				}
			}
			(*it)->users.push_back(user);
			join_rmInvit((*it), user);
			std::string rpl_join = ":" + user->nickname + " JOIN #" + (*it)->name + "\r\n";
			for (std::vector<User *>::iterator it2 = (*it)->users.begin(); it2 != (*it)->users.end(); ++it2)
			{
				send((*it2)->fd, rpl_join.c_str(), rpl_join.length(), 0);
				send_log((*it2)->fd, rpl_join, server);
			}
			for (std::vector<User *>::iterator it2 = (*it)->operators.begin(); it2 != (*it)->operators.end(); ++it2)
			{
				send((*it2)->fd, rpl_join.c_str(), rpl_join.length(), 0);
				send_log((*it2)->fd, rpl_join, server);
			}
			(*it)->printChannelUsers(JOIN);
			server->printServerChannels((*it)->name);
			std::string topic_mess = "TOPIC #" + (*it)->name + "\r\n";
			irc_topic(topic_mess, user, server);
			irc_names(*it, user, server);
			(*it)->nbUsers++;
			return ;
		}
	}
	Channel *channel = new Channel(token);
	channel->lastTopicUpdateWho = user->nickname;
	channel->nbUsers = 1;
	channel->operators.push_back(user);
	server->channels.push_back(channel);

	std::string rpl_join = ":" + user->nickname + " JOIN #" + channel->name + "\r\n";
	send(user->fd, rpl_join.c_str(), rpl_join.length(), 0);
	send_log(user->fd, rpl_join, server);

	channel->printChannelUsers(JOIN);
	server->printServerChannels(channel->name);
	irc_names(channel, user, server);
}

void irc_privmsg(std::string message, User *user, Server *server) {
    std::cout << COMMAND << "PRIVMSG" << std::endl;
    message = message.substr(8); // Remove the command "PRIVMSG"
    if (message[0] == '\0') {
        std::string err_need_more_param = ":127.0.0.1 461 " + user->nickname + " PRIVMSG :Not enough parameters\r\n";
        send(user->fd, err_need_more_param.c_str(), err_need_more_param.length(), 0);
        send_log(user->fd, err_need_more_param, server);
        return;
    }
    int i = 0;
    while (message[i] != ':') i++;
    std::string dest = message.substr(0, i - 1);
    if (dest[0] == '#' && !(*server->getChannelByName(dest))->isInChannel(user) && !(*server->getChannelByName(dest))->isOpInChannel(user))
        return;
    std::cout << PRIVMSG << "sent to " << dest << std::endl;
    message = message.substr(i + 1);
    std::cout << PRIVMSG << "\"" << message << "\"" << RESET << std::endl;
    if (dest[0] == '#') {
        dest = dest.substr(1);
        for (std::vector<Channel *>::const_iterator it = server->channels.begin(); it != server->channels.end(); it++) {
            if (dest == (*it)->name) {
                std::string rpl_privmsg = ":" + user->nickname + " PRIVMSG #" + (*it)->name + " :" + message + "\r\n";
                for (std::vector<User *>::const_iterator it2 = (*it)->users.begin(); it2 != (*it)->users.end(); it2++) {
                    if ((*it2)->fd != user->fd) {
                        send((*it2)->fd, rpl_privmsg.c_str(), rpl_privmsg.length(), 0);
                        send_log((*it2)->fd, rpl_privmsg, server);
                    }
                }
                for (std::vector<User *>::const_iterator it3 = (*it)->operators.begin(); it3 != (*it)->operators.end(); it3++) {
                    if ((*it3)->fd != user->fd) {
                        send((*it3)->fd, rpl_privmsg.c_str(), rpl_privmsg.length(), 0);
                        send_log((*it3)->fd, rpl_privmsg, server);
                    }
                }
                return;
            }
        }
        std::string err_no_such_channel = "127.0.0.1 403 " + user->nickname + " #" + dest + " :No such channel\r\n";
        send(user->fd, err_no_such_channel.c_str(), err_no_such_channel.length(), 0);
        send_log(user->fd, err_no_such_channel, server);
        return;
    } else {
        for (std::vector<User *>::const_iterator it = server->users.begin(); it != server->users.end(); it++) {
            if (dest == (*it)->nickname) {
                std::string rpl_privmsg = ":" + user->nickname + " PRIVMSG " + (*it)->nickname + " :" + message + "\r\n";
                send((*it)->fd, rpl_privmsg.c_str(), rpl_privmsg.length(), 0);
                send_log((*it)->fd, rpl_privmsg, server);
                return;
            }
        }
        std::string err_no_such_nick = "127.0.0.1 401 " + user->nickname + " " + dest + " :No such nickname\r\n";
        send(user->fd, err_no_such_nick.c_str(), err_no_such_nick.length(), 0);
        send_log(user->fd, err_no_such_nick, server);
        return;
    }
}

void irc_part(std::string message, User *user, Server *server) {
    int rc;
    std::cout << COMMAND << "PART" << std::endl;

    message = message.substr(6); // Remove the command "PART"
    std::string rpl_part = message;
    std::string channelName = rpl_part.substr(0, rpl_part.find(' '));
    rpl_part.erase(0, rpl_part.find(' ') + 2);
    std::string reason = rpl_part;
    rpl_part = ":" + user->nickname + " PART #" + channelName + " :" + rpl_part + "\r\n";

    for (std::vector<Channel *>::iterator it = server->channels.begin(); it != server->channels.end(); ++it) {
        if ((*it)->name == channelName) {
            (*it)->channelSendLoop(rpl_part, user->fd, server, 1);
            (*it)->nbUsers--;
            rc = (*it)->deleteChannelUser(user, server);
            if (rc == 1) {
                delete (*it);
                std::cout << DELETE << "Succesfully deleted channel #" << channelName << RESET << std::endl;
            }
        }
    }
}

void	irc_names(Channel *channel, User *user, Server *server)
{
	std::cout << COMMAND << "NAMES" << std::endl;
	std::string rpl_names = ":127.0.0.1 353 = #" + channel->name + " :";
	for (std::vector<User *>::iterator it = channel->operators.begin(); it != channel->operators.end(); ++it)
	{
		rpl_names += "@" + (*it)->nickname + " ";
	}
	for (std::vector<User *>::iterator it = channel->users.begin(); it != channel->users.end(); ++it)
	{
		rpl_names += (*it)->nickname + " ";
	}
	rpl_names += "\r\n";
	channel->channelSendLoop(rpl_names, user->fd, server, 1);
	std::string rpl_endnames = ":127.0.0.1 366 " + user->nickname + " #" + channel->name + " :End of /NAMES list.\r\n";
	channel->channelSendLoop(rpl_endnames, user->fd, server, 1);
}

void irc_quit(std::string message, User *user, Server *server) {
    std::cout << COMMAND << "QUIT" << std::endl;

    message = message.substr(6); // Remove the command "QUIT"
    std::string msg;
    if (message.empty()) {
        msg = "Quit";
    } else {
        msg = message;
    }

    std::string rpl_quit = ":" + user->nickname + " QUIT :Quit: " + msg + "\r\n";

    for (std::vector<Channel *>::iterator it = server->channels.begin(); it != server->channels.end(); ++it) {
        if ((*it)->isInChannel(user) || (*it)->isOpInChannel(user)) {
            (*it)->channelSendLoop(rpl_quit, user->fd, server, 0);
            (*it)->nbUsers--;
            int rc = (*it)->deleteChannelUser(user, server);
            if (rc == 1) {
                std::string name = (*it)->name;
                delete (*it);
                std::cout << DELETE << "Succesfully deleted channel #" << name << RESET << std::endl;
            } else {
                (*it)->printChannelUsers(QUIT);
            }
        }
    }

    for (std::vector<struct pollfd>::iterator it4 = server->fds.begin(); it4 != server->fds.end(); ++it4) {
        if ((*it4).fd == user->fd) {
            close((*it4).fd);
            (*it4).fd = -1;
        }
    }
    delete user;
}

void irc_topic(std::string message, User *user, Server *server) {
    std::string channel;
    std::string topic;
    std::vector<Channel *>::iterator it;
    std::vector<Channel *>::iterator ite = server->channels.end();
    std::time_t t = std::time(0);
    std::ostringstream oss;
    oss << t;
    std::string time_str = oss.str();

    std::cout << COMMAND << "TOPIC" << std::endl;

    if (message[0] == '\0') {
        std::string err_need_more_param = ":127.0.0.1 461 " + user->nickname + " TOPIC :Not enough parameters\r\n";
        send(user->fd, err_need_more_param.c_str(), err_need_more_param.length(), 0);
        send_log(user->fd, err_need_more_param, server);
        return;
    }

    size_t i = message.find(' ');
    channel = message.substr(6, i - 6);
    it = server->getChannelByName(channel);

    if (it == ite) {
        std::string rpl_not_valid_name = ":127.0.0.1 403 " + user->nickname + " #" + channel + " :No such channel\r\n";
        send(user->fd, rpl_not_valid_name.c_str(), rpl_not_valid_name.length(), 0);
        send_log(user->fd, rpl_not_valid_name, server);
        return;
    }

    if (!(*it)->isInChannel(user) && !(*it)->isOpInChannel(user)) {
        std::string rpl_not_valid_name = ":127.0.0.1 442 " + user->nickname + " #" + channel + " :You're not on that channel\r\n";
        send(user->fd, rpl_not_valid_name.c_str(), rpl_not_valid_name.length(), 0);
        send_log(user->fd, rpl_not_valid_name, server);
        return;
    }

    if (message[i] == '\0') {
        if ((*it)->topic.empty()) {
            std::string rpl_no_topic = ":127.0.0.1 331 " + user->nickname + " #" + channel + " :No topic is set\r\n";
            send(user->fd, rpl_no_topic.c_str(), rpl_no_topic.length(), 0);
            send_log(user->fd, rpl_no_topic, server);
            return;
        } else {
            std::string rpl_topic = ":127.0.0.1 332 " + user->nickname + " #" + channel + " :" + (*it)->topic + "\r\n";
            send(user->fd, rpl_topic.c_str(), rpl_topic.length(), 0);
            send_log(user->fd, rpl_topic, server);
            std::string rpl_time = ":127.0.0.1 333 " + user->nickname + " #" + channel + " " + (*it)->lastTopicUpdateWho + " " + (*it)->lastTopicUpdateWhen + "\r\n";
            send(user->fd, rpl_time.c_str(), rpl_time.length(), 0);
            send_log(user->fd, rpl_time, server);
            return;
        }
    } else {
        if ((*it)->isModeT()) {
            if (!(*it)->isOpInChannel(user)) {
                std::string rpl_not_op = ":127.0.0.1 482 " + user->nickname + " #" + channel + " :You're not channel operator\r\n";
                send(user->fd, rpl_not_op.c_str(), rpl_not_op.length(), 0);
                send_log(user->fd, rpl_not_op, server);
                return;
            }
        }
        message = message.substr(i + 2);
        topic = message;
        (*it)->topic = topic;
        (*it)->lastTopicUpdateWhen = time_str;
        (*it)->lastTopicUpdateWho = user->nickname;
        std::string rpl_topic = ":" + user->nickname + " TOPIC #" + channel + " :" + topic + "\r\n";
        (*it)->channelSendLoop(rpl_topic, user->fd, server, 1);
        std::string rpl_time = ":127.0.0.1 333 " + user->nickname + " #" + channel + " " + (*it)->lastTopicUpdateWho + " " + (*it)->lastTopicUpdateWhen + "\r\n";
        (*it)->channelSendLoop(rpl_time, user->fd, server, 1);
    }
}

void irc_nick(std::string message, User *user, Server *server) {
    std::cout << COMMAND << "NICK" << std::endl;
    message = message.substr(5);
    size_t pos = message.find("\r\n");
    std::string newNick = message.substr(0, pos);
    std::string oldNick = user->nickname;

    user->nickname = newNick;

    int rc = server->checkNick(user->fd, newNick);

    if (rc != 0) {
        std::string rpl_error;
        std::ostringstream line;

        rc == 432 ? line << rc << " " << user->nickname << " :Erroneous nickname\r\n"
                  : line << rc << " " << user->nickname << " :Nickname is already in use\r\n";

        rpl_error = ":127.0.0.1 " + line.str();
        send(user->fd, rpl_error.c_str(), rpl_error.length(), 0);
        send_log(user->fd, rpl_error, server);
        return;
    }

    std::string rpl_nick = ":" + oldNick + " NICK " + newNick + "\r\n";

    for (std::vector<Channel *>::iterator it = server->channels.begin(); it != server->channels.end(); ++it) {
        if ((*it)->isInChannel(user) || (*it)->isOpInChannel(user)) {
            (*it)->channelSendLoop(rpl_nick, user->fd, server, 1);
        }
    }
}

void irc_mode(std::string *message, User *user, Server *server) {
    bool hasLastParam = false;
    std::cout << COMMAND << "MODE" << std::endl;
    *message = message->substr(6); // Exclut "MODE " du début

    size_t firstSpace = message->find(' ');
    std::string channelName = message->substr(0, firstSpace);
    *message = message->substr(firstSpace + 1);

    size_t secondSpace = message->find(' ');
    std::string mode = message->substr(0, secondSpace);
    if (channelName == mode)
        return;
    *message = message->substr(secondSpace + 1);

    std::string param = *message;
    if (param != mode)
        hasLastParam = true;

    std::string::iterator it = mode.begin();
    std::string::iterator ite = mode.end();
    int sign = -1;
    while (it != ite) 
	{
		if ((*it) == '+')
			sign = 1;
		else if ((*it) == '-')
			sign = 0;
		if ((*it) == 'o' && sign == 0)
		{
			std::cout << YELLOW << "Operator " << user->nickname << " try to remove operator privilege to " << param << RESET << std::endl;
			(*server->getChannelByName(channelName))->deOpUser(user, (*server->getChannelByName(channelName))->getUserByNick(param), server);
				return;
		}
		else if ((*it) == 'o' && sign == 1)
		{
			std::cout << YELLOW << "Operator " << user->nickname << " try to set user " << param << " has new channel operator" << RESET << std::endl;
			(*server->getChannelByName(channelName))->opUser(user, (*server->getChannelByName(channelName))->getUserByNick(param), server);
				return;
		}
		else if ((*it) == 'k' && sign == 0)
		{
			(*server->getChannelByName(channelName))->password.clear();
			std::cout << YELLOW << "Operator " << user->nickname << " unset password on channel #" << channelName << RESET << std::endl;
			return;
		}
		else if ((*it) == 'k' && sign == 1)
		{
			if (hasLastParam == true)
			{
				(*server->getChannelByName(channelName))->password = param;
				std::cout << YELLOW << "Operator " << user->nickname << " set password " << param << " has new channel password." << RESET << std::endl;
			}
			return;
		}
		if ((*it) >= 'a' && (*it) <= 'z' && sign == 1)
		{
			if ((*server->getChannelByName(channelName))->mode.find((*it)) == std::string::npos)
				(*server->getChannelByName(channelName))->mode.push_back((*it));
		}
		else if ((*it) >= 'a' && (*it) <= 'z' && sign == 0)
		{
			if ((*server->getChannelByName(channelName))->mode.find((*it)) != std::string::npos)
				(*server->getChannelByName(channelName))->mode.erase((*server->getChannelByName(channelName))->mode.find((*it)));
		}
		++it;
	}
}

void	irc_kick(std::string message, User * user, Server * server)
{
	std::istringstream iss(message);
    std::string word;
    std::getline(iss, word, ' '); // Read until the first space
    
    std::string rpl_kick = word;
    bool hasReason = (rpl_kick.find(':') != std::string::npos);

    std::getline(iss, word, ' '); // Read until the next space
    std::string channelName = word;

    std::getline(iss, word, ' '); // Read until the next space
    std::string kickedUser = word;

    std::string reason = "Kicked by operator";
	if (channelName.empty() || channelName == kickedUser)
	{
		std::string rpl_error = ":127.0.0.1 461 " + user->nickname + " KICK :Not enough parameters\r\n";
		send(user->fd, rpl_error.c_str(), rpl_error.length(), 0);
		send_log(user->fd, rpl_error, server);
		return;
	}
    std::vector<Channel *>::iterator it = server->getChannelByName(channelName);
    if (it == server->channels.end())
	{
		std::string rpl_error = ":127.0.0.1 403 " + user->nickname + " #" + channelName + " :No such channel\r\n";
		send(user->fd, rpl_error.c_str(), rpl_error.length(), 0);
		send_log(user->fd, rpl_error, server);
		return;
	}
	if (!(*server->getChannelByName(channelName))->isOpInChannel((*server->getUserByName(kickedUser))) && !(*server->getChannelByName(channelName))->isInChannel((*server->getUserByName(kickedUser))))
	{
		std::string rpl_error = ":127.0.0.1 403 " + user->nickname + " " + kickedUser + " #" + channelName + " :They aren't on that channel\r\n";
		send(user->fd, rpl_error.c_str(), rpl_error.length(), 0);
		send_log(user->fd, rpl_error, server);
		return;
	}
	if (!(*server->getChannelByName(channelName))->isOpInChannel(user) && !(*server->getChannelByName(channelName))->isInChannel(user))
	{
		std::string rpl_error = ":127.0.0.1 442 " + user->nickname + " #" + channelName + " :You're not on that channel\r\n";
		send(user->fd, rpl_error.c_str(), rpl_error.length(), 0);
		send_log(user->fd, rpl_error, server);
		return;
	}
	if (!(*it)->isOpInChannel(user) || !(*it)->isBestOp(user, (*it)->getUserByNick(kickedUser)))
	{
		std::cout << ERROR << user->nickname << " is not operator or have less privileges than " << kickedUser << ", can't kick it." << RESET << std::endl;
		std::string rpl_error = ":127.0.0.1 403 " + user->nickname + " #" + channelName + " :You're not channel operator\r\n";
		send(user->fd, rpl_error.c_str(), rpl_error.length(), 0);
		send_log(user->fd, rpl_error, server);
		return;
	}
	if (hasReason)
	{
		std::getline(iss, reason);
	}
	
	rpl_kick = ":" + user->nickname + " KICK #" + channelName + " " + kickedUser + " :" + reason + "\r\n";
	(*it)->channelSendLoop(rpl_kick, user->fd, server, 1);
	int rc = (*it)->deleteChannelUser((*it)->getUserByNick(kickedUser), server);
	if (rc == 1)
	{
		std::string name = (*it)->name;
		delete (*it);
		std::cout << DELETE << "Succesfully deleted channel " << "#" << name << RESET << std::endl;
	}
}

void	irc_invite(std::string message, User *user, Server *server)
{
	std::istringstream iss(message);
    std::string word;
    std::getline(iss, word, ' '); // Read until the first space
    
    std::string nick = word;
    std::getline(iss, word, ' '); // Read until the next space
    std::string channel = word;

    std::vector<Channel *>::iterator it = server->getChannelByName(channel);
    if (it == server->channels.end()) {
        std::string rpl_not_in_channel = ":127.0.0.1 403 " + user->nickname + " #" + channel + " :No such channel\r\n";
		send(user->fd, rpl_not_in_channel.c_str(), rpl_not_in_channel.length(), 0);
		send_log(user->fd, rpl_not_in_channel, server);
		std::cout << ERROR << "No channel found." << RESET << std::endl;
	}
	else
	{
		std::vector<User *>::iterator	it2 = server->getUserByName(nick);
		if (it2 == server->users.end())
		{
			std::string	rpl_no_such_nick = ":127.0.0.1 401 " + user->nickname + " " + nick + " :No such nickname\r\n";
			send(user->fd, rpl_no_such_nick.c_str(), rpl_no_such_nick.length(), 0);
			send_log(user->fd, rpl_no_such_nick, server);
			std::cout << ERROR << "No user found." << RESET << std::endl;
			return ;
		}
		if ((*it)->isInChannel(*it2)  || (*it)->isOpInChannel(*it2))
		{
			std::string rpl_already_in_channel = ":127.0.0.1 443 " + user->nickname + " #" + channel + " " + nick + " :is already on channel\r\n";
			send(user->fd, rpl_already_in_channel.c_str(), rpl_already_in_channel.length(), 0);
			send_log(user->fd, rpl_already_in_channel, server);
			std::cout << ERROR << "User already in channel." << RESET << std::endl;
			return ;
		}
		std::string rpl_invite = ":" + user->nickname + " INVITE " + nick + " #" + channel + "\r\n";
		send((*it2)->fd, rpl_invite.c_str(), rpl_invite.length(), 0);
		send_log((*it2)->fd, rpl_invite, server);
		(*it)->invitedUsers.push_back(*it2);
		std::cout << INVITE << " > " << user->nickname << " invite " << nick << " in #" << channel << "." << RESET << std::endl;
	}
}