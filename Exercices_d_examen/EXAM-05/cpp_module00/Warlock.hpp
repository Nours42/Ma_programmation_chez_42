/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:02:32 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 22:05:22 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

class   Warlock
{
    private:
        
        Warlock & operator=(Warlock const & ref);
        Warlock(Warlock const & ref);
        Warlock(void);
        std::string _name;
        std::string _title;

    protected:
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        std::string const & getName() const;
        std::string const & getTitle() const;
        void        setTitle(std::string const & str);
        void        introduce() const;
};
#endif