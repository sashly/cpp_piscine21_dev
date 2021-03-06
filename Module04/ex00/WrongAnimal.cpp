#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) {}

WrongAnimal::WrongAnimal( WrongAnimal const &src ) : type( src.getType() ) {}

WrongAnimal::~WrongAnimal( void ) {}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &rhs ) {

	if (this != &rhs) {
		this->type = rhs.getType();
	}
	return (*this);
}

void	WrongAnimal::makeSound( void ) const {

	std::cout << "Animal::makeSound\n";
}

std::string const	&WrongAnimal::getType( void ) const {

	return ( this->type );
}
