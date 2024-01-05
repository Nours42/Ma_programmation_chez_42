#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"

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
	Fireball* fireball = new Fireball();
	Polymorph* polymorph = new Polymorph();
	BrickWall const brickwall;
	BrickWall stonewall;
	BrickWall *steelwall = new BrickWall();

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
	bella.launchSpell("Fwoosh", brickwall);
	bella.launchSpell("Fwoosh", stonewall);
	bella.launchSpell("Fwoosh", *steelwall);
	bella.learnSpell(fireball);
	bella.learnSpell(polymorph);
	bella.launchSpell("Fireball", dummy);
	bella.launchSpell("Fireball", puppet);
	bella.launchSpell("Fireball", *chucky);
	bella.launchSpell("Fireball", brickwall);
	bella.launchSpell("Fireball", stonewall);
	bella.launchSpell("Fireball", *steelwall);
	bella.forgetSpell("Fwoosh");
	bella.forgetSpell("Fireball");
	bella.launchSpell("Fwoosh", dummy);
	bella.launchSpell("Fwoosh", puppet);
	bella.launchSpell("Fwoosh", *chucky);
	bella.launchSpell("Fwoosh", brickwall);
	bella.launchSpell("Fwoosh", stonewall);
	bella.launchSpell("Fwoosh", *steelwall);
	bella.launchSpell("Fireball", dummy);
	bella.launchSpell("Fireball", puppet);
	bella.launchSpell("Fireball", *chucky);
	bella.launchSpell("Fireball", brickwall);
	bella.launchSpell("Fireball", stonewall);
	bella.launchSpell("Fireball", *steelwall);

	// test jack(Warlock pointer)
	jack->introduce();
	std::cout << jack->getName() << " - " << jack->getTitle() << std::endl;
	jack->setTitle("the Mighty");
	jack->introduce();
	jack->learnSpell(fwoosh);
	jack->launchSpell("Fwoosh", dummy);
	jack->launchSpell("Fwoosh", puppet);
	jack->launchSpell("Fwoosh", *chucky);
	jack->launchSpell("Fwoosh", brickwall);
	jack->launchSpell("Fwoosh", stonewall);
	jack->launchSpell("Fwoosh", *steelwall);
	jack->launchSpell("Fireball", dummy); // lancer un sort aui n'a pas ete appris
	jack->launchSpell("Fireball", puppet);
	jack->launchSpell("Fireball", *chucky);
	jack->launchSpell("Fireball", brickwall);
	jack->launchSpell("Fireball", stonewall);
	jack->launchSpell("Fireball", *steelwall);
	jack->forgetSpell("Fwoosh");
	jack->forgetSpell("Fireball"); // forget a spell qui n'a pas ete appris
	jack->launchSpell("Fwoosh", dummy);
	jack->launchSpell("Fwoosh", puppet);
	jack->launchSpell("Fwoosh", *chucky);
	jack->launchSpell("Fwoosh", brickwall);
	jack->launchSpell("Fwoosh", stonewall);
	jack->launchSpell("Fwoosh", *steelwall);
	jack->launchSpell("Fireball", dummy);
	jack->launchSpell("Fireball", puppet);
	jack->launchSpell("Fireball", *chucky);
	jack->launchSpell("Fireball", brickwall);
	jack->launchSpell("Fireball", stonewall);
	jack->launchSpell("Fireball", *steelwall);

	delete jack;

	return (0);
}