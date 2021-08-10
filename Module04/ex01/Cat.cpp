#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( Brain const &brain ) : Animal() {

	this->brain = new Brain();
	*this->brain = brain;
}

Cat::Cat( Cat const &src ) : Animal( src ) {

	this->deepCopy( src );
}

Cat::~Cat( void ) {

	delete this->brain;
}

Cat	&Cat::operator=( Cat const &rhs ) {

	if (this != &rhs) {
		this->Animal::operator=( rhs );
		this->deepCopy( rhs );
	}
	return (*this);
}

void	Cat::makeSound( void ) const {

	std::cout << "meow meow meow...\n";
}

void	Cat::deepCopy(const Cat &src) {

	if ( this != &src ) {
		delete this->brain;
		if (src.brain)
			this->brain = new Brain( *(src.brain) );
		else
			this->brain = src.brain;
	}
}
