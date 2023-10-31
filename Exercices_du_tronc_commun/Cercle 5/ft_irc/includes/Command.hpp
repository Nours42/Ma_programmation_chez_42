/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:01 by nours42           #+#    #+#             */
/*   Updated: 2023/10/31 10:32:58 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

class	Command
{
	private:
		
		Command(Command const &ref);				//no used
		Command &operator=(Command const &ref);		//no used
		
	protected:
	public:

		Command();
		virtual ~Command(void) {}
		virtual bool onCommand(User* sender, std::vector<std::string> args) = 0;
};

#endif