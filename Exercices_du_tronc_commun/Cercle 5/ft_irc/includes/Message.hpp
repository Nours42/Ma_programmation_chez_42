/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:07:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/01 16:27:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

//////	REPONSE SERVER	//////

# define RPL_AWAY				"001"	//	<nick><away message>
# define RPL_CHANNELMODEIS		"002"	//	<channel><mode><mode params>
# define RPL_CREATED			"003"	//	<server>						This server was created
# define RPL_ENDOFEXCEPTLIST	"004"	//	<channel>						End of channel exception list
# define RPL_ENDOFINVITELIST	"005"	//	<channel>						End of channel invite list
# define RPL_ENDOFMOTD			"006"	//	<MotD>							End of MOTD command
# define RPL_EXCEPTLIST			"007"	//	<channel><exceptionmask>
# define RPL_INVITELIST			"008"	//	<channel><invitemask>
# define RPL_INVITING			"009"	//	<channel><nick>
# define RPL_LIST				"010"	//	<channel><# visible>	<topic>
# define RPL_LISTEND			"011"	//	<list>							End of LIST
# define RPL_LISTSTART			"012"	//	<channel>						Channel :Users  Name
# define RPL_MOTD				"013"	//	<text>
# define RPL_MOTDSTART			"014"	//	<server>						Message of the day
# define RPL_MYINFO				"015"	//	<server>						I have your hostname,servername, and version
# define RPL_NOTOPIC			"016"	//	<channel>						No topic is set
# define RPL_NOWAWAY			"017"	//	<user>							You have been marked as being away
# define RPL_TIME				"018"	//	<server><version><comments>
# define RPL_TOPIC				"019"	//	<channel><topic>
# define RPL_UMODEIS			"020"	//	<user>							User mode
# define RPL_UNAWAY				"021"	//	<user>							You are no longer marked as being away
# define RPL_USERHOST			"022"	//	<nick>=<user>@<host>
# define RPL_VERSION			"023"	//	<version><debuglevel><server><comments>
# define RPL_WELCOME			"024"	//									Welcome to the Internet Relay Network
# define RPL_YOUREOPER			"025"	//									You are now an IRC operator
# define RPL_YOURHOST			"026"	//									Your host is

//////	ERROR	///////

//	Password error

# define ERR_PASSWDMISMATCH		"202"	//	<password>	Password incorrect

//	Channel error

# define ERR_NOSUCHCHANNEL		"300"	//	<channel>	No such channel name
# define ERR_CANNOTSENDTOCHAN	"301"	//	<channel>	Cannot send to channel name
# define ERR_TOOMANYCHANNELS	"302"	//	<channel>	You have joined too many channels
# define RPL_BANLIST			"303"	//	<channel>
# define RPL_ENDOFBANLIST		"304"	//	<channel>	End of channel ban list
# define ERR_UNKNOWNMODE		"305"	//	<channel>	is unknown mode char to me for <channel>
# define RPL_NAMREPLY			"306"	//	<channel>
# define RPL_ENDOFNAMES			"307"	//	<channel>	End of NAMES list
# define ERR_USERNOTINCHANNEL	"308"	//	<channel>	This User aren't on that channel
# define ERR_NOTONCHANNEL		"309"	//	<channel>	You're not on that channel
# define ERR_NOCHANMODES		"310"	//	<channel>	Channel doesn't support modes
# define ERR_BADCHANMASK		"311"	//	<channel>	Bad Channel Mask
# define ERR_CHANOPRIVSNEEDED	"312"	//	<channel>	You're not channel operator
# define ERR_KEYSET				"313"	//	<channel>	Channel key already set
# define ERR_CHANNELISFULL		"314"	//	<channel>	Cannot join channel (+l)
# define ERR_INVITEONLYCHAN		"315"	//	<channel>	Cannot join channel (+i)
# define ERR_BANNEDFROMCHAN		"316"	//	<channel>	Cannot join channel (+b)
# define ERR_BADCHANNELKEY		"317"	//	<channel>	Cannot join channel (+k)
# define ERR_BANLISTFULL		"318"	//	<channel>	Channel list is full

//	User error

# define ERR_USERONCHANNEL		"400"	//	<user>					is already on channel
# define ERR_USERSDONTMATCH		"401"	//	<user>					Cannot change mode for other users
# define ERR_NOLOGIN			"402"	//	<user>					User not logged in
# define ERR_USERSDISABLED		"403"	//	<user>					USERS has been disabled
# define ERR_NOTREGISTERED		"404"	//	<user>					You have not registered
# define ERR_ALREADYREGISTRED	"405"	//	<user>					Unauthorized command (already registered)
# define ERR_NOSUCHNICK			"406"	//	<user><nickname>		No such nick/channel
# define ERR_NONICKNAMEGIVEN	"407"	//	<user><nickname>		No nickname given
# define ERR_ERRONEUSNICKNAME	"408"	//	<user><nickname>		Erroneus nickname
# define ERR_NICKNAMEINUSE		"409"	//	<user><nickname>		Nickname is already in use.
# define ERR_NICKCOLLISION		"410"	//	<user><nickname>		Nickname collision KILL
# define ERR_WASNOSUCHNICK		"411"	//	<user><nickname>		There was no such nickname
# define ERR_NEEDREGGEDNICK		"412"	//	<user><nickname>		You need a registered nick to do this
# define ERR_NOPRIVILEGES		"413"	//	<user><permission>		Permission Denied- You're not an IRC operator
# define ERR_RESTRICTED			"414"	//	<user><permission>		Your connection is restricted
# define ERR_UNIQOPPRIVSNEEDED	"415"	//	<user><permission>		You must be at least a half-operator to do this

//	mode error

# define ERR_UMODEUNKNOWNFLAG	"500"	//	<mode>					Unknown MODE flag

//	server error

# define ERR_NOSUCHSERVER		"600"	//	<server>				No such server

//	command error

# define ERR_NORECIPIENT		"700"	//	<command>				No recipient given (<command>)
# define ERR_UNKNOWNCOMMAND		"701"	//	<command>				Unknown command
# define ERR_NEEDMOREPARAMS		"702"		//	<command>				Not enough parameters

//	other error

# define ERR_TOOMANYTARGETS		"800"	//	Duplicate recipients. No message delivered
# define ERR_NOORIGIN			"801"	//	No origin specified
# define ERR_NOTEXTTOSEND		"802"	//	No text to send
# define ERR_NOTOPLEVEL			"803"	//	No toplevel domain specified
# define ERR_WILDTOPLEVEL		"804"	//	Wildcard in toplevel domain
# define ERR_NOMOTD				"805"	//	MOTD File is missing
# define ERR_NOADMININFO		"806"	//	No administrative info available
# define ERR_FILEERROR			"807"	//	File error doing <file op> on <file>
# define ERR_SUMMONDISABLED		"808"	//	SUMMON has been disabled
# define ERR_NOOPERHOST			"809"	//	No O-lines for your host
# define ERR_MSGTOOLONG			"810"		//	Msg > a 512 char

#endif