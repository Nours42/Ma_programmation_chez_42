/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/21 18:21:11 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <ctime>
# include <cctype>
# include <cstddef>
# include <cstdlib>
# include <exception>
# include <iomanip>
# include <ios>
# include <iostream>
# include <iterator>
# include <limits>
# include <list>
# include <ostream>
# include <sstream>
# include <stdexcept>
# include <string>
# include <utility>
# include <vector>

# define VECTOR 0
# define VERBOSE 0
# define LIST 1

/////// COLORS ///////

# define RESET	"\e[0m"

# define BOLD	"\e[1m"
# define DIM	"\e[2m"
# define ITAL	"\e[3m"
# define ULINE	"\e[4m"

# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"
# define WHITE	"\e[37m"

# define BRIGHT_BLACK	"\e[90m"
# define BRIGHT_RED		"\e[91m"
# define BRIGHT_GREEN	"\e[92m"
# define BRIGHT_YELLOW	"\e[93m"
# define BRIGHT_BLUE	"\e[94m"
# define BRIGHT_PURPLE	"\e[95m"
# define BRIGHT_CYAN	"\e[96m"
# define BRIGHT_WHITE	"\e[97m"

# define BG_BLACK	"\e[40m"
# define BG_RED		"\e[41m"
# define BG_GREEN	"\e[42m"
# define BG_YELLOW	"\e[43m"
# define BG_BLUE	"\e[44m"
# define BG_PURPLE	"\e[45m"
# define BG_CYAN	"\e[46m"
# define BG_WHITE	"\e[47m"

# define BG_BRIGHT_BLACK	"\e[100m"
# define BG_BRIGHT_RED		"\e[101m"
# define BG_BRIGHT_GREEN	"\e[102m"
# define BG_BRIGHT_YELLOW	"\e[103m"
# define BG_BRIGHT_BLUE		"\e[104m"
# define BG_BRIGHT_PURPLE	"\e[105m"
# define BG_BRIGHT_CYAN		"\e[106m"
# define BG_BRIGHT_WHITE	"\e[107m"

bool				isADuplicate( int *array, int array_size, int nb );
int					*getArrayToSort( int ac, char **av );
int					getNumber( char *nbStr, int *array, int array_size );
void				printLine( std::string color, std::string key, std::string value);
void				printTime(std::string containerType, std::clock_t time, int elements);
void				testPmergeMe( int ac, char **av );
std::clock_t		test_vector( int *array, int array_size);
std::clock_t		test_list( int *array, int array_size );
std::string			getContentsAsString( std::vector<int> &vector );
std::string			getContentsAsString( std::vector< std::pair<int, int> > &vector );
std::string			getContentsAsString( std::list<int> &list );
std::string			getContentsAsString( std::list< std::pair<int, int> > &list );
std::vector<int>	*convertArrayToVector( int *array, int array_size );

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

template <typename T>
void verifySortAccuracy( int *array, int array_size, T &resultContainer );

class PmergeMe
{
	private:
		/////// Canonical Form ///////
		PmergeMe( void );

		bool				_container;
		int					_straggler;
		std::vector<int>	*_unsortedVector;
		std::vector<int>	*_sortedVector;
		std::list<int>		*_unsortedList;
		std::list<int>		*_sortedList;

		bool								_isVectorAlreadySorted( void );
		bool								_isListAlreadySorted( void );
		int									_getJacobstahlNumber( int n );
		int									_bisect( std::vector<int> vector, int x );
		int									_bisect( std::list<int> list, int x );
		void								_fillVectorFromArray( int *array, int array_size );
		void								_sortVector( void );
		void 								_sortEachPair( std::vector< std::pair<int, int> > &splitVector );
		void								_sortPairsByLargestValue( std::vector< std::pair<int, int> > &splitVector );
		void								_insertionSortPairs( std::vector< std::pair<int, int> > &splitVector, int n );
		void								_insertElement( std::vector< std::pair<int, int> > &splitVector, std::pair<int, int> element, int n );
		void								_createSortedSequence( std::vector< std::pair<int, int> > &splitVector );
		void								_insertAtBisectedIndex( std::vector<int> &vector, int element );
		void								_extractStraggler( std::vector<int> &unsortedVector );
		void								_insertStraggler( std::vector<int> &sortedVector );
		void								_fillListFromArray( int *array, int array_size );
		void								_sortList( void );
		void								_sortEachPair( std::list< std::pair<int, int> > &splitList );
		void								_sortPairsByLargestValue( std::list< std::pair<int, int> > &splitList );
		void								_insertionSortPairs( std::list< std::pair<int, int> > &splitList, int n );
		void								_insertElement( std::list< std::pair<int, int> > &splitList, std::pair<int, int> element, int n );
		void								_createSortedSequence( std::list< std::pair<int, int> > &splitList );
		void								_insertAtBisectedIndex( std::list<int> &list, int element );
		void								_extractStraggler( std::list<int> &unsortedList );
		void								_insertStraggler( std::list<int> &sortedList );
		template <typename T>
		void 								_printVector( std::vector<T> &vector, std::string name, std::string color );	
		template <typename T>
		void _printList( std::list<T> &list, std::string name, std::string color );
		
		std::list< std::pair<int, int> > 	_splitIntoPairs( std::list<int> &unsortedList );
		std::list<int>						_createIndexInsertSequence( std::list<int> pending );
		std::list<int>						_buildJacobstahlInsertionSequence( std::list<int> pending );
		std::string							_getVectorContentsAsString( std::vector<int> &vector );
		std::string							_getVectorContentsAsString( std::vector< std::pair<int, int> > &vector );
		std::string							_getListContentsAsString( std::list<int> &list );
		std::string							_getListContentsAsString( std::list< std::pair<int, int> > &list );
		std::vector<int>					_createIndexInsertSequence( std::vector<int> pending );
		std::vector<int>					_buildJacobstahlInsertionSequence( int size );
		std::vector< std::pair<int, int> >	_splitIntoPairs( std::vector<int> &unsortedVector );

	public:
		/////// Canonical Form ///////
		PmergeMe( int* array, int array_size, bool container );
		PmergeMe( PmergeMe &src );
		~PmergeMe( void );
		PmergeMe &operator=( PmergeMe &src );
		
		void				sort( void );
		std::vector<int>	&getSortedVector( void );
		std::list<int>		&getSortedList( void );
};

#endif