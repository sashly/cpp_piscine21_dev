#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal() {

	std::cout << "------> Default Dog constructor called\n";
	this->type = "Dog";
}

Dog::Dog( Dog const &src ) : Animal( src ) {

	std::cout << "------> Dog Copy constructor called\n";
}

Dog::~Dog( void ) { std::cout << "------> Dog destructor called\n"; }

Dog	&Dog::operator=( Dog const &rhs ) {

	this->Animal::operator=( rhs );
	return (*this);
}

void	Dog::makeSound( void ) const {

	std::cout << "woof woof woof...\n";
}
