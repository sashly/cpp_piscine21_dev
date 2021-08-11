A#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal() {

	std::cout << "------> Default Dog constructor called\n";
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog( Dog const &src ) : Animal( src ) {

	std::cout << "------> Dog Copy constructor called\n";
	if (src.brain)
		this->brain = new Brain( *(src.brain) );
	else
		this->brain = src.brain;
}

Dog::~Dog( void ) {

	std::cout << "------> Dog destructor called\n";
	delete this->brain;
}

Dog	&Dog::operator=( Dog const &rhs ) {

	if (this != &rhs) {
		this->Animal::operator=( rhs );
		delete this->brain;
		if (rhs.brain)
			this->brain = new Brain( *(rhs.brain) );
		else
			this->brain = rhs.brain;
	}
	return (*this);
}

void	Dog::makeSound( void ) const {

	std::cout << "woof woof woof...\n";
}

void		Dog::setIdea( std::string const &idea ) {

	if (this->brain)
		this->brain->setIdea( idea );
}

void		Dog::printIdeas( void ) const {

	if (this->brain)
		this->brain->printIdeas();
}
