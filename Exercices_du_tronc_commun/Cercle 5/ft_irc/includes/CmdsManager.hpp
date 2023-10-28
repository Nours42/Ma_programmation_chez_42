/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdsManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:01 by nours42           #+#    #+#             */
/*   Updated: 2023/10/28 18:55:04 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDSMANAGER_HPP
# define CMDSMANAGER_HPP

# include "Ircserv.hpp"

class	CmdsManager
{
	private:
	protected:
	public:
		CmdsManager();
		~CmdsManager();
		CmdsManager(CmdsManager const &ref);
		CmdsManager &operator=(CmdsManager const &ref);

        void    getCommands(void) const;
};

#endif