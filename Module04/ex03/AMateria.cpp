#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( void ) {}

AMateria::AMateria( std::string const & t ) : type( t ) {}

AMateria::AMateria( AMateria const &src ) : type( src.getType() ) {}

AMateria::~AMateria( void ) {}

AMateria	&AMateria::operator=( AMateria const &rhs ) {

	if (this != &rhs) {
		this->type = rhs.getType();
	}
	return (*this);
}

std::string const	&AMateria::getType( void ) const {

	return ( this->type );
}

void 		AMateria::use( ICharacter& target ) {

	(void)target;
}
