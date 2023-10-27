/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:27:54 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/10 14:05:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.h"
#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"

int	main(void)
{
	std::cout << RED << "\n*** creating a new spellbook ***" << std::endl << std::endl << NO_COLOR;
	MateriaSource *spellBook = new MateriaSource();
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	
	
	std::cout << RED << "\n*** copying spellbook ***" << std::endl << std::endl << NO_COLOR;
	IMateriaSource *spellBookCopy = new MateriaSource(*spellBook);
	
	
	std::cout << RED << "\n*** learn new spells ***" << std::endl << std::endl << NO_COLOR;
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	
	
	std::cout << RED << "\n*** learn new spells ***" << std::endl << std::endl << NO_COLOR;
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	delete spellBook;
	
	
	std::cout << RED << "\n*** creating a new character ***" << std::endl << std::endl << NO_COLOR;
	AMateria *tmp;
	Character *testDummy = new Character("Test-Dummy");
	
	tmp = spellBookCopy->createMateria("cure");
	testDummy->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	testDummy->equip(tmp);


	std::cout <<  RED << "\n*** copy the a new character ***" << std::endl << std::endl << NO_COLOR;
	ICharacter *testDummyCopy = new Character(*testDummy);
	
	testDummyCopy->use(1, *testDummy);
	testDummyCopy->use(0, *testDummy);

	delete testDummyCopy;
	delete testDummy;


	std::cout << RED << "\n*** creating a new character ***" << std::endl << std::endl << NO_COLOR;
	ICharacter *Gandalf = new Character("Gandalf");

	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	Gandalf->equip(tmp);
	Gandalf->unequip(0);
	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	
	
	std::cout << RED << "\n*** creating another new character ***" << std::endl << std::endl << NO_COLOR;
	ICharacter *Grima = new Character("Grima \"langue de serpent \"");
	Gandalf->use(0, *Grima);
	Gandalf->use(1, *Grima);
	Grima->use(0, *Gandalf);
	Grima->use(1, *Gandalf);
	
	
	std::cout << RED << "\n*** destroying character Grima ***" << std::endl << std::endl << NO_COLOR;
	delete Grima;


	std::cout << RED << "\n*** destroying character Gandalf ***" << std::endl << std::endl << NO_COLOR;
	delete Gandalf;

	
	std::cout << RED << "\n*** destroying spellbook ***" << std::endl << std::endl << NO_COLOR;
	delete spellBookCopy;

	return (0);
}