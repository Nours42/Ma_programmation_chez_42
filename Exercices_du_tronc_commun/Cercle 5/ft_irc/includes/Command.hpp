/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:01 by nours42           #+#    #+#             */
/*   Updated: 2023/10/30 16:07:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "Server.hpp"
# include "CmdsManager.hpp"

class	Command
{
	private:

		Command(Command const &ref);				//no used
		Command &operator=(Command const &ref);		//no used
		
	protected:
	public:
	
		Command(void) {};
		~Command(void) {};
};

#endif