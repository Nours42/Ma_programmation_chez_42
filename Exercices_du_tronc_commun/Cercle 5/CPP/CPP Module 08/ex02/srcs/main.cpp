/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:21:52 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/19 05:10:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

void	printLine(void)
{
	std::cout << std::endl << "------------------------------------------------" << std::endl;
}

int main(void)
{
	
	std::cout << std::endl << "premier exemple avec des INT :" << std::endl;
	printLine();
	std::cout << "Creation de la MutantStack composee de int et contenant les nombres : 5, 17, 42, -4 et 12345 " << std::endl;
	MutantStack<int> mstack;
	mstack.push(5); 
	mstack.push(17);
	mstack.push(42);
	mstack.push(12345);
	mstack.push(-4);
	std::cout << "Top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "(la size comporte un element 0 et est donc = a size + 1)" << std::endl;
	std::cout << "ajout des nombres : 31, 58, 77, -489, 849545, 0 et 192" << std::endl;
	mstack.push(31);
	mstack.push(58);
	mstack.push(77);
	mstack.push(-489);
	mstack.push(849545);
	mstack.push(0);
	mstack.push(192);
	std::cout << "Top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "Begin : " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << std::endl << "All the values in the stack : " << std::endl;
	printLine();
	while (it != ite + 1)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "Deuxieme exemple avec des CHAR :" << std::endl;
	printLine();
	MutantStack<char>	mcstack;
	std::cout << "Creation de la MutantStack composee de char et contenant A et B " << std::endl;
	mcstack.push('A'); 
	mcstack.push('B');
	std::cout << "Top: " << mcstack.top() << std::endl;
	mcstack.pop();
	std::cout << "Size: " << mcstack.size() << std::endl;
	std::cout << "(la size comporte un element 0 et est donc = a size + 1)" << std::endl;
	std::cout << "ajout des lettres : C, D, E, F, G, H et I" << std::endl;
	mcstack.push('C');
	mcstack.push('D');
	mcstack.push('E');
	mcstack.push('F');
	mcstack.push('G');
	mcstack.push('H');
	mcstack.push('I');
	MutantStack<char>::iterator it2 = mcstack.begin();
	std::cout << "Begin: " << *it2 << std::endl;
	MutantStack<char>::iterator it2e = mcstack.end();
	++it2;
	--it2;
	std::cout << std::endl << "All the values in the stack : " << std::endl;
	printLine();
	while (it2 != it2e)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;
}