/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:45 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/30 15:34:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODECOMMAND_HPP
# define MODECOMMAND_HPP

# include "../Server.hpp"

class ModeCommand : public Command
{
	private :

		ModeCommand(ModeCommand const &ref);				//no used
		ModeCommand &operator=(ModeCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		ModeCommand(Server* sever);
		~ModeCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif