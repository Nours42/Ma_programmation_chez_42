#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->_name = name;
	this->_title = title;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock() {}

Warlock & Warlock::operator=(Warlock const & ref)
{
	this->_name = ref._name;
	this->_title = ref._title;
	return *this;
}

Warlock::Warlock(Warlock const & ref)
{
	*this = ref;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string	const & Warlock::getName() const
{
	return (_name);
}

std::string	const & Warlock::getTitle() const
{
	return (_title);
}

void		Warlock::setTitle(std::string const & str)
{
	_title = str;
}
void		Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void        Warlock::learnSpell(ASpell *ptrASpell)
{
	Book.learnSpell(ptrASpell);
}

void        Warlock::forgetSpell(std::string spellName)
{
	Book.forgetSpell(spellName);
}

void        Warlock::launchSpell(std::string spellName, ATarget const &refAtarget)
{
	ATarget const *test = 0;
	if (test == &refAtarget)
		return ;
	ASpell* spell = Book.createSpell(spellName);
	if (spell)
		spell->launch(refAtarget);
}
