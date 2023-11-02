/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:01 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 16:03:56 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <vector>
// # include "../Console.hpp"
// # include "../Utils.hpp"
# include "../User.hpp"
// # include "../Message.hpp"

class	Command
{
	private:
		
		// Command(Command const &ref);					//no used
		// Command &operator=(Command const &ref);		//no used
		
	protected:
	public:

		// Command();									//no used
		virtual ~Command(void) {}
		virtual bool onCommand(User* sender, std::vector<std::string> args) = 0;
};

class	CmdsManager
{
	private:

		// CmdsManager(CmdsManager const &ref);				//no used
		// CmdsManager &operator=(CmdsManager const &ref);		//no used

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

		bool call(const std::string &cmd_name, const std::vector<std::string>& args, User* sender)
		{
			std::cout << "cmdsManager.call : " << cmd_name << std::endl;
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