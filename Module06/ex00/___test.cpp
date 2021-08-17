#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

//clang++ -Wall -Wextra -Werror -std=c++98 ___test.cpp

int	main( void ) {

//	std::cout << GREEN <<"\t--> CHAR: <--" << RESET << "\n";
//	std::cout << std::numeric_limits<char>::max() << "\n";
//	std::cout << std::numeric_limits<char>::max() << "\n";
//
//	std::cout << GREEN <<"\n\t--> INT: <--" << RESET << "\n";
//	std::cout << std::numeric_limits<int>::max() << "\n";
//	std::cout << std::numeric_limits<int>::min() << "\n";
//
//	std::cout << GREEN <<"\n\t--> FLOAT: <--" << RESET << "\n";
//	std::cout << std::numeric_limits<float>::max() << "\n";
//	std::cout << std::numeric_limits<float>::min() << "\n";
//	std::cout << std::numeric_limits<float>::epsilon() << "\n";
//	std::cout << std::numeric_limits<float>::infinity() << "\n";
//	std::cout << std::numeric_limits<float>::infinity() * ( -1 ) << "\n";
//	std::cout << std::numeric_limits<float>::quiet_NaN() << "\n";
//	std::cout << std::numeric_limits<float>::signaling_NaN() << "\n";
//
//	std::cout << GREEN <<"\n\t--> DOUBLE: <--" << RESET << "\n";
//	std::cout << std::numeric_limits<double>::max() << "\n";
//	std::cout << std::numeric_limits<double>::min() << "\n";
//	std::cout << std::numeric_limits<double>::epsilon() << "\n";
//	std::cout << std::numeric_limits<double>::infinity() << "\n";
//	std::cout << std::numeric_limits<double>::infinity() * ( -1 ) << "\n";
//	std::cout << std::numeric_limits<double>::quiet_NaN() << "\n";
//	std::cout << std::numeric_limits<double>::signaling_NaN() << "\n";

	std::cout << GREEN <<"\n\t--> STRTOD TESTS: <--" << RESET << "\n";

	std::string	arg( "nan" );
	std::cout << arg.find( "inf" ) << "\n";
	char const *str = arg.c_str();

	char *end;
	double	out;

	out = std::strtod( str, &end );
	std::cout << "Convert {" << str << "} to double --> |" << out
			  << "|, end --> {" << end << "}\n";


	return ( 0 );
}

