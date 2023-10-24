/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:08 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/24 15:14:17 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
	private:

		std::string	_name;
		std::string _title;
		Warlock();
		Warlock(Warlock const &ref);
		Warlock &operator=(Warlock const &ref);
	
	protected:
	public:

		~Warlock();
		Warlock(std::string const &name, std::string const &title);
		
		//// setter ////

		void	setTitle(std::string const &newTitle);

		//// getter ////

		std::string	const &getName() const;
		std::string	const &getTitle() const;

		//// other ////
		void		introduce() const;

};

#endif