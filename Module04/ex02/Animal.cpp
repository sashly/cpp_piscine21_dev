#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) {

	std::cout << "------> Default Animal constructor called\n";
}

Animal::Animal( Animal const &src ) : type( src.type ) {

	std::cout << "------> Animal Copy constructor called\n";
}

Animal::~Animal( void ) { std::cout << "------> Animal destructor called\n"; }

Animal	&Animal::operator=( Animal const &rhs ) {

	if (this != &rhs) {
		this->type = rhs.type;
	}
	return ( *this );
}

std::string const	&Animal::getType( void ) const {

	return ( this->type );
}
