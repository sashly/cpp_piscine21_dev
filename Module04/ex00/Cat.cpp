#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal() {
	this->type = "Cat";
}

Cat::Cat( Cat const &src ) : Animal( src ) {}

Cat::~Cat( void ) {}

Cat	&Cat::operator=( Cat const &rhs ) {

	if (this != &rhs) {
		this->Animal::operator=( rhs );
	}
	return (*this);
}

void	Cat::makeSound( void ) const {

	std::cout << "meow meow meow...\n";
}
