#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) {}

Animal::Animal( Animal const &src ) : type( src.type ) {}

Animal::~Animal( void ) {}

Animal	&Animal::operator=( Animal const &rhs ) {

	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}

void	Animal::makeSound( void ) const {

	std::cout << "Animal::makeSound\n";
}

std::string const	&Animal::getType( void ) const {

	return ( this->type );
}
