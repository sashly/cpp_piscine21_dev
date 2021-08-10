#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal() {
	this->type = "Dog";
}

Dog::Dog( Dog const &src ) : Animal( src ) {}

Dog::~Dog( void ) {}

Dog	&Dog::operator=( Dog const &rhs ) {

	if (this != &rhs) {
		this->Animal::operator=( rhs );
	}
	return (*this);
}

void	Dog::makeSound( void ) const {

	std::cout << "woof woof woof...\n";
}
