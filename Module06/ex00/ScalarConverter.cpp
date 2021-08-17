#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <limits>

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( std::string const arg ) : raw_val_( 0. ),
															is_char( false ),
															is_pinf( false ),
															is_ninf( false ),
															is_nan( false ) {
	if (arg.size() == 3 && arg[0] == '\'' && arg[2] == '\'')
		this->is_char = true;
	else if ( arg == "inf" || arg == "INF")
		this->is_pinf = true;
	else if ( arg == "-inf" || arg == "-INF")
		this->is_ninf = true;
	else if ( arg == "nan" || arg == "INF")
		this->is_pinf = true;
	else {
		this->raw_val_ = std::atof( arg.c_str() );
		if ()
	}
}

ScalarConverter::ScalarConverter( ScalarConverter const &src ) {}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter	&ScalarConverter::operator=( ScalarConverter const &rhs ) {

	if (this != &rhs) {

	}
	return (*this);
}
