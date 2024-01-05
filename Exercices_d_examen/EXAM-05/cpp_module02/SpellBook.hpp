#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:

		SpellBook(SpellBook const &ref);
		SpellBook &operator=(SpellBook const &ref);
		std::map<std::string, ASpell*>	spBook;

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *ptrASpell);
		void forgetSpell(std::string const &ref);
		ASpell* createSpell(std::string const &ref);

};
#endif