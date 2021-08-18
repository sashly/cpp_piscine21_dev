#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cfloat>
#include <limits>
#include <cerrno>
#include <cmath>

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( std::string const arg ) : raw_val_( 0. ),
															type_( INV ),
													is_spec_float_( false ) {

	if (arg.size() == 3 && arg[0] == '\'' && arg[2] == '\'')
		this->char_input( arg[1] );
	else {
		char const	*in = arg.c_str();
		char 		*end;

		errno = 0;
		this->raw_val_ = std::strtod( in, &end );
		if (errno == ERANGE)
			return ;
		if ( end[0] == '\0' ||
				((end[0] == 'f' || end[0] == 'F') && end[1] == '\0')) {
			if (arg.find( '.' ) != std::string::npos
					|| arg.find( 'e' ) != std::string::npos
					|| arg.find( 'E' ) != std::string::npos
					|| ScalarConverter::is_spec_double( this->raw_val_ )) {
				this->is_spec_float_
					= ScalarConverter::is_spec_double( this->raw_val_ );
				this->type_ = DOUBLE;
				if (end[0] == 'f' || end[0] == 'F')
					this->type_ = FLOAT;
			}
			else if (end[0] == '\0')
				this->type_ = INT;
			this->is_input_valid();
		}
	}
}

ScalarConverter::~ScalarConverter( void ) {}

void	ScalarConverter::convert( void ) const {

	this->convert_char();
	this->convert_int();
	this->convert_float();
	this->convert_double();
}

ScalarConverter::ScalarConverter( ScalarConverter const &src ) { (void)src; }

ScalarConverter	&ScalarConverter::operator=( ScalarConverter const &rhs ) {

	if (this != &rhs) {
		(void)rhs;
	}
	return (*this);
}

void	ScalarConverter::char_input( char c ) {

	this->type_ = CHAR;
	this->raw_val_ = static_cast<double>( c );
}

bool	ScalarConverter::is_spec_double( double val ) {
	if (val == std::numeric_limits<double>::infinity()
	|| val == -std::numeric_limits<double>::infinity()
	|| val != val)
		return ( true );
	return ( false );
}

void	ScalarConverter::is_input_valid( void ) {

	if (this->type_ == INT && (this->raw_val_ < static_cast<double>( INT_MIN )
			|| this->raw_val_ > static_cast<double>( INT_MAX )))
		this->type_ = INV;
	else if (this->type_ == FLOAT && !this->is_spec_float_
		&& (this->raw_val_ < std::numeric_limits<float>::lowest()
			|| this->raw_val_ > std::numeric_limits<float>::max()))
		this->type_ = INV;
}

void	ScalarConverter::convert_char( void ) const {

	char	c = static_cast<char>( this->raw_val_ );

	std::cout << "char: ";
	if (this->type_ == INV || this->is_spec_float_
			|| c < std::numeric_limits<char>::min()
			|| c > std::numeric_limits<char>::max())
		std::cout << "impossible";
	else if (!std::isprint( c ))
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << "\n";
}

void	ScalarConverter::convert_int( void ) const {

	int	i = static_cast<int>( this->raw_val_ );

	std::cout << "int: ";
	if (this->type_ == INV || this->is_spec_float_
		|| this->raw_val_ < static_cast<double>( INT_MIN )
		|| this->raw_val_ > static_cast<double>( INT_MAX ))
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << "\n";
}

template<typename T>
bool	is_float_without_frac( T in ) {

	T	frac = in - static_cast<T>( static_cast<int>( in ) );
	if (std::abs( frac ) < std::numeric_limits<T>::epsilon())
		return ( true );
	return ( false );
}

void	ScalarConverter::convert_float( void ) const {

	float	f = static_cast<float>( this->raw_val_ );

	std::cout << "float: ";
	if (this->type_ == INV || (!this->is_spec_float_
	&& (f < std::numeric_limits<float>::lowest()
		|| f > std::numeric_limits<float>::max())))
		std::cout << "impossible";
	else if (this->is_spec_float_)
		std::cout << this->raw_val_ << "f";
	else
		std::cout << f << ((is_float_without_frac<float>( f )) ? ".0f" : "f");
	std::cout << "\n";
}

void	ScalarConverter::convert_double( void ) const {

	std::cout << "double: ";
	if (this->type_ == INV)
		std::cout << "impossible";
	else
		std::cout << this->raw_val_
			<< ((is_float_without_frac<double>( this->raw_val_ )) ? ".0" : "");
	std::cout << "\n";
}

void	ScalarConverter::debug( void ) const {

	std::cout << "Type is: ";
	if (this->type_ == INV)
		std::cout << "invalid\n";
	if (this->type_ == CHAR)
		std::cout << "char\n";
	if (this->type_ == INT)
		std::cout << "int\n";
	if (this->type_ == FLOAT)
		std::cout << "float\n";
	if (this->type_ == DOUBLE)
		std::cout << "double\n";
	std::cout << "Raw value: " << this->raw_val_ << "\n";
}
