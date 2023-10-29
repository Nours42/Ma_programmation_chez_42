/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdsManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:01 by nours42           #+#    #+#             */
/*   Updated: 2023/10/29 18:49:01 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDSMANAGER_HPP
# define CMDSMANAGER_HPP

# include "Server.hpp"
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
		
        void    getCommands(void) const;
};

#endif