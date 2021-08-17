#include "Data.hpp"
#include <iostream>

Data::Data( void ) : val_( 0 ) {}

Data::Data( int const v ) : val_( v ) {}

Data::Data( Data const &src ) {

	*this = src;
}

Data::~Data( void ) {}

Data	&Data::operator=( Data const &rhs ) {

	if (this != &rhs) {
		this->val_ = rhs.getVal();
	}
	return ( *this );
}

int		Data::getVal( void ) const {

	return ( this->val_ );
}

void	Data::hello( void ) const {

	std::cout << "Hello, World!\n";
}

