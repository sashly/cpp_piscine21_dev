#include "easyfind.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>
#include <list>

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

template<class InputIt>
void	print_container( InputIt start, InputIt end, char const *msg ) {
	std::cout << msg << ":";
	while (start != end)
		std::cout << " " << *start++;
	std::cout << "\n";
}

//	default template arguments for a function template are a C++11 extension
template<class T, int tcase_size>
int		generate_test_case( T &t, int mod ) {
	for (int i = 0; i < tcase_size; i++)
		t.push_back( std::rand() % mod );
	return ( std::rand() % mod );
}

//	assumed T is a sequence int container
template<class T, int tcase_size>
void	easyfind_test( int mod, char const *cont_name ) {
	T	v;
	int val = generate_test_case<T, tcase_size>( v, mod );
	std::cout << GREEN <<"\t--> before find: <--" << RESET << "\n";
	print_container( v.begin(), v.end(), cont_name );
	typename T::iterator	it = easyfind<T>( v, val );
	std::cout << GREEN <<"\t--> after find val " << val
	<< ": <--" << RESET << "\n";
	print_container( it, v.end(), cont_name );
}

int	main( void ) {
	std::srand( std::time( 0 ) );

	easyfind_test<std::vector<int>, 25>( 25, "vector" );
	std::cout << "\n";
	easyfind_test<std::list<int>, 25>( 25, "list" );
	std::cout << "\n";
	easyfind_test<std::deque<int>, 25>( 25, "deque" );

	return ( 0 );
}


