#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal() {

	std::cout << "------> Default Cat constructor called\n";
	this->type = "Cat";
}

Cat::Cat( Cat const &src ) : Animal( src ) {

	std::cout << "------> Cat Copy constructor called\n";
}

Cat::~Cat( void ) { std::cout << "------> Cat destructor called\n"; }

Cat	&Cat::operator=( Cat const &rhs ) {

	this->Animal::operator=( rhs );
	return (*this);
}

void	Cat::makeSound( void ) const {

	std::cout << "meow meow meow...\n";
}
