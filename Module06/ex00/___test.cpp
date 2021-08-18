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

	std::string	arg( "0e0" );
//	std::cout << arg.find( "inf" ) << "\n";
	char const *str = arg.c_str();

	char *end;
	double	out;

	out = std::strtod( str, &end );
	std::cout << "Convert {" << str << "} to double --> |" << out
			  << "|, end --> {" << end << "}\n";

	std::cout << GREEN <<"\n\t--> CONVERSION TESTS: <--" << RESET << "\n";

	double	d = 2147483649;

	std::cout << static_cast<int>( d ) << "\n";

	return ( 0 );
}

//	3.14159
//	3.14159E0
//	0.
//	0.0
//	.0
//	.0001
//	0e0
//	1.7976931348623157E+308
//	-1.7976931348623157E+308

//max: 3.40282e+038 min: 1.17549e-038

//-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000 Double lowest
//179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000 Double max

//-340282346638528859811704183484516925440.0000000000000000 Float lowest
//340282346638528859811704183484516925440.0000000000000000 Float max

