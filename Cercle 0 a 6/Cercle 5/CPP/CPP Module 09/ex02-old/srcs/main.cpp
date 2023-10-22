/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/22 09:14:36 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

template <typename T>
void	printContainer( std::vector<T> &vector, std::string name, std::string color )
{
	std::stringstream ss;
	ss << name << " vector (size " << vector.size() << "): ";
	printLine( color, ss.str(), getContentsAsString( vector ) );
}

template <typename T>
void printContainer( std::list<T> &list, std::string name, std::string color )
{
	std::stringstream ss;
	ss << "-- " << name << " list (size " << list.size() << "): ";
	printLine( color, ss.str(), getContentsAsString( list ) );
}

void testPmergeMe( int ac, char **av )
{
	int array_size = ac - 1;
	int *array = getArrayToSort( array_size, av );
	
	std::clock_t vectorTime = test_vector( array, array_size );
	std::clock_t listTime = test_list( array, array_size );
	
	std::cout << std::endl << CYAN "---- Timing" RESET << std::endl;
	printTime("vector", vectorTime, ac - 1);
	printTime("list", listTime, ac - 1);

	delete [] array;
}

std::clock_t test_vector( int *array, int array_size)
{
	std::cout << CYAN "---- Insertion-merge sort with std::vector" RESET << std::endl;
	PmergeMe vectorSorter( array, array_size, VECTOR );
	std::clock_t start = std::clock();
	vectorSorter.sort();
	std::clock_t vectorTime = std::clock() - start;
	verifySortAccuracy( array, array_size, vectorSorter.getSortedVector() );
	return ( vectorTime );
}

std::clock_t test_list( int *array, int array_size )
{
	std::cout << std::endl << CYAN "---- Insertion-merge sort with std::list" RESET << std::endl;
	PmergeMe listSorter( array, array_size, LIST );
	std::clock_t start = std::clock();
	listSorter.sort();
	std::clock_t listTime = std::clock() - start;
	verifySortAccuracy( array, array_size, listSorter.getSortedList() );
	return ( listTime );
}

void printTime(std::string containerType, std::clock_t time, int elements)
{
	double clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;
	double timeInMs = time / clock_per_ms;

	std::cout << "Time to process a range of " << elements << " elements with std::" << containerType << ": " << time << " clock ticks (";
	std::cout << std::fixed;
	std::cout.precision( 6 );
	std::cout << timeInMs << " ms)" << std::endl;
}

template <typename T>
void verifySortAccuracy( int *array, int array_size, T &resultContainer )
{
	std::vector<int> *control = convertArrayToVector( array, array_size );

	printContainer( *control, "Before Sort", RESET );
	std::sort(control->begin(), control->end());

	std::vector<int>::iterator controlit = control->begin();
	typename T::iterator resultit = resultContainer.begin();
	while (resultit != resultContainer.end() &&controlit != control->end())
	{
		if ( *resultit != *controlit )
		{
			printContainer( resultContainer, "After Sort", RED );
			printContainer( *control, "Expected", CYAN );
			std::cout << std::endl << RED BOLD ">>> KO: incorrectly sorted !" RESET << std::endl;
			delete control;
			return ;
		}
		resultit++;
		controlit++;
	}
	printContainer( resultContainer, "After Sort", GREEN );
	std::cout << std::endl << GREEN BOLD ">>> OK: properly sorted." RESET << std::endl;
	delete control;
}

int *getArrayToSort( int array_size, char **av )
{
	int *array = new int[array_size];
	int x = 0;
	while (x < array_size)
	{
		array[x] = 0;
		x++;
	}
	x = 0;
	while (av[x + 1] &&x < array_size)
	{
		int nb = getNumber( av[x + 1], array, array_size );
		array[x] = nb;
		x++;
	}
	return ( array );
}

int getNumber( char *nbStr, int *array, int array_size )
{
	long nb = atol( nbStr );
	std::stringstream intMax;
	intMax << std::numeric_limits<int>::max();

	if ( nb < 1 || nb > std::numeric_limits<int>::max() )
	{
		delete [] array;
		throw ( std::out_of_range( std::string( nbStr ) + ": must be a positive integer between 1 and " + intMax.str() ) );
	}
	if ( isADuplicate( array, array_size, nb ) )
	{
		delete [] array;
		throw ( std::out_of_range( std::string( nbStr ) + ": duplicate number" ) );
	}
	return ( nb );
}

bool isADuplicate( int *array, int array_size, int nb )
{
	int i = 0;

	while (i < array_size)
	{
		if ( array[i] == nb )
			return ( true );
		i++;
	}
	return ( false );
}

std::vector<int> *convertArrayToVector( int *array, int array_size )
{
	std::vector<int> *vector = new std::vector<int>();
	int i = 0; 

	while (i < array_size)
	{
		vector->push_back(array[i]);
		i++;
	}
	return ( vector );
}

void printLine( std::string color, std::string key, std::string value)
{
	std::cout << color << std::setw( 35 ) << std::left << key << value << RESET << std::endl;
}

std::string getContentsAsString( std::vector<int> &vector )
{
	std::stringstream ss;
	if ( vector.empty() )
		return ( "" );
	std::vector<int>::iterator it = vector.begin();
	while (it != vector.end())
	{
		ss << "[" << *it << "]";
		it++;
	}
	return ( ss.str() );
}

std::string getContentsAsString( std::vector< std::pair<int, int> > &vector )
{
	std::stringstream ss;
	if ( vector.empty() )
		return ( "" );
	std::vector< std::pair<int, int> >::iterator it = vector.begin();
	while(it != vector.end())
	{
		ss << "[" << it->first << "--"  << it->second << "]";
		it++;
	}
	return ( ss.str() );
}

std::string getContentsAsString( std::list<int> &list )
{
	std::stringstream ss;
	if ( list.empty() )
		return ( "" );
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		ss << "[" << *it << "]";
		it++;
	}
	return ( ss.str() );
}

std::string getContentsAsString( std::list< std::pair<int, int> > &list )
{
	std::stringstream ss;
	if ( list.empty() )
		return ( "" );
	std::list< std::pair<int, int> >::iterator it = list.begin();
	while (it != list.end())
	{
		ss << "[" << it->first << "--"  << it->second << "]";
		it++;
	}
	return ( ss.str() );
}

int	main( int ac, char **av )
{
	if ( ac < 2 )
	{
		std::cerr << RED "Usage: ./PmergeMe [integers to sort]" RESET << std::endl;
		return ( 1 );
	}
	try
	{
		testPmergeMe( ac, av );
	}
	catch ( std::exception &e )
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		return ( 1 );
	}
	return ( 0 );
}