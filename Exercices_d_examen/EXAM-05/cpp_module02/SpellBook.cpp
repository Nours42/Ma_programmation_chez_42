#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell*>::iterator it_begin = this->spBook.begin();
	std::map<std::string, ASpell*>::iterator it_end = this->spBook.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->spBook.clear();
}

void SpellBook::learnSpell(ASpell *ptrASpell)
{
	if (ptrASpell)
		spBook.insert(std::pair<std::string, ASpell *>(ptrASpell->getName(), ptrASpell->clone()));
}

void SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell*>::iterator it = spBook.find(spellName);
	if (it != spBook.end())
		delete it->second;
	spBook.erase(spellName);
}

ASpell* SpellBook::createSpell(std::string const &spellName)
{
	std::map<std::string, ASpell*>::iterator it = spBook.find(spellName);
	if (it != spBook.end())
		return spBook[spellName];
	return NULL;
}