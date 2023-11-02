/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:33:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 18:32:55 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

class Warlock
{
    private:
        
        std::string _name;
        std::string _title;

		Warlock();
		Warlock(Warlock const &ref);
		Warlock &operator=(Warlock const &ref);

    protected:
    public:

		/// COPELIAN ///
		Warlock(std::string name, std::string title);
		~Warlock();
		
		
		std::string const	&getName() const;
		std::string const	&getTitle() const;
		void				setTitle(std::string const &str);
		void				introduce() const;
};

#endif