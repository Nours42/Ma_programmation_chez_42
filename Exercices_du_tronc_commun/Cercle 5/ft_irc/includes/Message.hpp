/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:07:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/01 09:41:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP
////// REPONSE SERVER //////

# define RPL_INVITING			"1" // :"<channel> <nick>"
# define RPL_EXCEPTLIST          "348" // :<channel> <exceptionmask>
# define RPL_ENDOFEXCEPTLIST     "349" // :<channel> :End of channel exception list
# define RPL_INVITELIST          "346" // :<channel> <invitemask>
# define RPL_ENDOFINVITELIST     "347" // :<channel> :End of channel invite list
# define RPL_UMODEIS				"221" // User mode
# define RPL_NOTOPIC				"331" // :<channel> :No topic is set
# define RPL_TOPIC				"332" // :<channel> :<topic>

////// ERROR ///////

// registered error
# define ERR_NOTREGISTERED		"1" // :You have not registered

// ressources error
# define ERR_NOSUCHNICK			"2" // :<nickname> :No such nick/channel
# define ERR_NEEDMOREPARAMS		"3" // <command> :Not enough parameters
# define ERR_USERONCHANNEL		"4" // :is already on channel
# define ERR_USERNOTINCHANNEL	"5" // <nick> <channel> :This User aren't on that channel
# define ERR_MSGTOOLONG			"6" // Msg > a 512 char

// places error
# define ERR_NOTONCHANNEL		"3" // :You're not on that channel
# define ERR_NOSUCHCHANNEL		"4" // :<channel name> :No such channel
# define ERR_NOCHANMODES			"477" // :Channel doesn't support modes
# define ERR_BADCHANMASK			"476" // :Bad Channel Mask

// ban error
# define RPL_BANLIST             "367" // :<channel> <banmask>
# define RPL_ENDOFBANLIST        "368" // :<channel> :End of channel ban list

// admin error
# define ERR_CHANOPRIVSNEEDED	"1" // :You're not channel operator

// mode error

# define ERR_UNKNOWNMODE			"472" // :is unknown mode char to me for <channel>
# define RPL_CHANNELMODEIS		"324" // :<channel> <mode> <mode params>
# define ERR_USERSDONTMATCH		"502" // :Cannot change mode for other users
# define ERR_UMODEUNKNOWNFLAG	"501" // :Unknown MODE flag

#endif