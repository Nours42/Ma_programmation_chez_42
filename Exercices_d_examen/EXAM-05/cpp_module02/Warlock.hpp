/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:02:32 by nours42           #+#    #+#             */
/*   Updated: 2023/11/10 12:01:49 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class SpellBook;

class   Warlock
{
    private:
        
        Warlock & operator=(Warlock const & ref);
        Warlock(Warlock const & ref);
        Warlock(void);
        std::string _name;
        std::string _title;
        SpellBook   Book;

    protected:
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        std::string const & getName() const;
        std::string const & getTitle() const;
        void        setTitle(std::string const & str);
        void        introduce() const;
        void        learnSpell(ASpell *ptrASpell);
        void        forgetSpell(std::string spellName);
        void        launchSpell(std::string spellName, ATarget const &refAtarget);
};
#endif