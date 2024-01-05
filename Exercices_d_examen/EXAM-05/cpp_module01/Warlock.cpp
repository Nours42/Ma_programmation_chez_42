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

void Warlock::learnSpell(ASpell *spell_ptr)
{
	if (spell_ptr)
		arr.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
}

void Warlock::forgetSpell(std::string spell_name)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(spell_name);
	if (it != arr.end())
		delete it->second;
	arr.erase(spell_name);
}

void Warlock::launchSpell(std::string spell_name, ATarget const &target_ref)
{
	ASpell* spell = arr[spell_name];
	if (spell)
		spell->launch(target_ref);
}