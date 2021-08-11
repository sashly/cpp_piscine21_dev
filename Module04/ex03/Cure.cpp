#include "Cure.hpp"
#include <iostream>

Cure::Cure( void ) : AMateria( "cure" ) {}

Cure::Cure( Cure const &src ) : AMateria( src ) {}

Cure::~Cure( void ) {}

Cure	&Cure::operator=( Cure const &rhs ) {

	this->AMateria::operator=( rhs );
	return (*this);
}

AMateria* 	Cure::clone( void ) const {

	return ( new Cure() );
}

void	Cure::use( ICharacter& target ) {

	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
