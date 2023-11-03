/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:02:32 by nours42           #+#    #+#             */
/*   Updated: 2023/11/03 06:05:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

class   Warlock
{
    private:
        
        Warlock & operator=(Warlock const & ref);
        Warlock(Warlock const & ref);
        Warlock(void);
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell*> arr;

    protected:
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        std::string const & getName() const;
        std::string const & getTitle() const;
        void        setTitle(std::string const & str);
        void        introduce() const;

        void    learnSpell(ASpell *ASpell_ptr);
        void    forgetSpell(std::string name);
        void    launchSpell(std::string name, ATarget const &ATarget_ref);
};
#endif