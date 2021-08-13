#include "Ice.hpp"
#include <iostream>

Ice::Ice( void ) : AMateria( "ice" ) {}

Ice::Ice( Ice const &src ) : AMateria( src ) {}

Ice::~Ice( void ) {}

Ice	&Ice::operator=( Ice const &rhs ) {

	this->AMateria::operator=( rhs );
	return ( *this );
}

AMateria* 	Ice::clone( void ) const {

	return ( new Ice() );
}

void		Ice::use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
