#include "span.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

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

template<class T, int tcase_size>
void	generate_test_case( T &t, int mod ) {
	for (int i = 0; i < tcase_size; i++)
		t.push_back( std::rand() % mod );
}

int	main( void ) {
	std::srand( std::time( 0 ) );
	{
		std::cout << GREEN <<"\t--> SUBJECT TEST: <--" << RESET << "\n";
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << GREEN <<"\t--> EXCEPTION TEST: <--" << RESET << "\n";
		try {
			Span	sp1( 2 );
			sp1.addNumber( 1 );
			sp1.addNumber( 2 );
			sp1.addNumber( 3 );
		}
		catch ( std::exception const &e ) {
			std::cout << "addNumber exception: " << e.what() << "\n";
		}
		try {
			Span				sp1( 10 );
			std::vector<int>	v( 8, 1 );
			sp1.addNumber( 1 );
			sp1.addNumber( 2 );
			sp1.addNumber( 3 );
			sp1.addRange( v.begin(), v.end() );
		}
		catch ( std::exception const &e ) {
			std::cout << "addRange exception: " << e.what() << "\n";
		}
		try {
			Span	sp1( 5 );
			sp1.addNumber( 4 );
			std::cout << "shortestSpan: " << sp1.shortestSpan() << "\n";
		}
		catch ( std::exception const &e ) {
			std::cout << "shortestSpan exception: " << e.what() << "\n";
		}
		try {
			Span	sp1( 5 );
			std::cout << "longestSpan: " << sp1.longestSpan() << "\n";
		}
		catch ( std::exception const &e ) {
			std::cout << "longestSpan exception: " << e.what() << "\n";
		}
	}
	{
		std::cout << GREEN <<"\t--> 10000 numbers TEST: <--" << RESET << "\n";
		std::vector<int>	tv;
		generate_test_case<std::vector<int>, 1000>( tv, 10000 );
		Span sp = Span( tv.size() );
		for (size_t i = 0; i < tv.size(); i++)
			sp.addNumber( tv[i] );
		std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
		std::cout << "longestSpan: " << sp.longestSpan() << "\n";
	}
	{
		std::cout << GREEN <<"\t--> 10000 numbers TEST: <--" << RESET << "\n";
		std::vector<int>	tv;
		generate_test_case<std::vector<int>, 10000>( tv, 100000 );
		Span sp = Span( tv.size() );
		sp.addRange( tv.begin(), tv.end() );
		std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
		std::cout << "longestSpan: " << sp.longestSpan() << "\n";
	}
	{
		std::cout << GREEN <<"\t--> 1000000 numbers TEST: <--" << RESET << "\n";
		std::vector<int>	tv;
		generate_test_case<std::vector<int>, 1000000>( tv, 10000000 );
		Span sp = Span( tv.size() );
		sp.addRange( tv.begin(), tv.end() );
		std::cout << "!\n";
		std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
		std::cout << "longestSpan: " << sp.longestSpan() << "\n";
	}
	return ( 0 );
}
