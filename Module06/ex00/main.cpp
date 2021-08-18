#include "ScalarConverter.hpp"
#include <iostream>

int	main( int argc, char **argv ) {

	if (argc == 2) {
		ScalarConverter	conv( argv[1] );
//		conv.debug();
//		std::cout << "-------------------\n";
		conv.convert();
	}
	else
		std::cout << "Usage: ./convert <literal "
					 "(char, int, float or double)>;\n";
	return ( 0 );
}
