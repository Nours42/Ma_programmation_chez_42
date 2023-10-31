/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdsManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:01 by nours42           #+#    #+#             */
/*   Updated: 2023/10/31 15:18:25 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDSMANAGER_HPP
# define CMDSMANAGER_HPP

# include <iostream>
# include <memory>
# include <vector>
# include <map>
# include "Utils.hpp"
# include "Command.hpp"

class	CmdsManager
{
	private:

		CmdsManager(CmdsManager const &ref);				//no used
		CmdsManager &operator=(CmdsManager const &ref);		//no used

		std::map<std::string, Command*> _cmds;
		
	protected:
	public:
	
		CmdsManager(void) {};
		~CmdsManager(void) { _cmds.clear(); };
		
        void	getCommands(void) const;
		void	on(std::string cmd_name, Command* cmd)
		{
			 _cmds[Utils::str_toupper(cmd_name)] = cmd;
		};

		bool call(std::string cmd_name, std::vector<std::string> args, User* sender)
		{
			if (!this->has(cmd_name))
				return false;
			return _cmds[Utils::str_toupper(cmd_name)]->onCommand(sender, args);
		};
		
		bool has(std::string cmd_name)
		{
			return _cmds.count(Utils::str_toupper(cmd_name)) == 1;
		};

};

#endif