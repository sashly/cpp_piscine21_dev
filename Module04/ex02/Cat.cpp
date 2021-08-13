#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal() {

	std::cout << "------> Default Cat constructor called\n";
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( Cat const &src ) {

	std::cout << "------> Cat Copy constructor called\n";
	this->type = src.getType();
	if (src.brain)
		this->brain = new Brain( *(src.brain) );
	else
		this->brain = src.brain;
}

Cat::~Cat( void ) {

	std::cout << "------> Cat destructor called\n";
	delete this->brain;
}

Cat	&Cat::operator=( Cat const &rhs ) {

	if (this != &rhs) {
		this->type = rhs.getType();
		delete this->brain;
		if (rhs.brain)
			this->brain = new Brain( *(rhs.brain) );
		else
			this->brain = rhs.brain;
	}
	return (*this);
}

void	Cat::makeSound( void ) const {

	std::cout << "meow meow meow...\n";
}

void		Cat::setIdea( std::string const &idea ) {

	if (this->brain)
		this->brain->setIdea( idea );
}

void		Cat::printIdeas( void ) const {

	if (this->brain)
		this->brain->printIdeas();
}
