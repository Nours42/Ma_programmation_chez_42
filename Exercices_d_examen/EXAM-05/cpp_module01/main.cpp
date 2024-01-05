#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"


int main()
{
	// test de creation des variables en const et pointeurs
	Warlock const richard("Richard", "Mistress of Magma");
	Warlock bella("Bella", "the red");
	Warlock* jack = new Warlock("Jack", "the Long");
	Dummy const dummy;
	Dummy puppet;
	Dummy *chucky = new Dummy();
	Fwoosh*	fwoosh = new Fwoosh();

	// test richard (Warlock const)
	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

	// test bella (Warlock)
	bella.introduce();
	std::cout << bella.getName() << " - " << bella.getTitle() << std::endl;
	bella.learnSpell(fwoosh);
	bella.launchSpell("Fwoosh", dummy);
	bella.launchSpell("Fwoosh", puppet);
	bella.launchSpell("Fwoosh", *chucky);
	bella.forgetSpell("Fwoosh");
	bella.launchSpell("Fwoosh", dummy);
	bella.launchSpell("Fwoosh", puppet);
	bella.launchSpell("Fwoosh", *chucky);

	// test jack(Warlock pointer)
	jack->introduce();
	std::cout << jack->getName() << " - " << jack->getTitle() << std::endl;
	jack->setTitle("the Mighty");
	jack->introduce();
	jack->learnSpell(fwoosh);
	jack->launchSpell("Fwoosh", dummy);
	jack->launchSpell("Fwoosh", puppet);
	jack->launchSpell("Fwoosh", *chucky);
	jack->forgetSpell("Fwoosh");
	jack->launchSpell("Fwoosh", dummy);
	jack->launchSpell("Fwoosh", puppet);
	jack->launchSpell("Fwoosh", *chucky);

	delete jack;

	return (0);
}