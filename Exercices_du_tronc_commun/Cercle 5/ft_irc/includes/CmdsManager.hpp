/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdsManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:01 by nours42           #+#    #+#             */
/*   Updated: 2023/10/30 16:04:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDSMANAGER_HPP
# define CMDSMANAGER_HPP

# include "Server.hpp"

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