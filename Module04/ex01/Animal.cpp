#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) {

	std::cout << "------> Default Animal constructor called\n";
}

Animal::Animal( Animal const &src ) : type( src.getType() ) {

	std::cout << "------> Animal Copy constructor called\n";
}

Animal::~Animal( void ) { std::cout << "------> Animal destructor called\n"; }

Animal	&Animal::operator=( Animal const &rhs ) {

	if (this != &rhs) {
		this->type = rhs.getType();
	}
	return ( *this );
}

void	Animal::makeSound( void ) const {

	std::cout << "Animal::makeSound\n";
}

std::string const	&Animal::getType( void ) const {

	return ( this->type );
}
