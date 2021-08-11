#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal() {

	std::cout << "Default Cat constructor called\n";
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( Brain const &brain ) : Animal() {

	std::cout << "Parameter Cat constructor called\n";
	this->brain = new Brain();
	*this->brain = brain;
}

Cat::Cat( Cat const &src ) : Animal( src ) {

	std::cout << "Cat Copy constructor called\n";
	this->deepCopy( src );
}

Cat::~Cat( void ) {

	std::cout << "Cat destructor called\n";
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

void		Cat::setIdea( std::string const &idea ) {

	if (this->brain)
		this->brain->setIdea( idea );
}

void		Cat::printIdeas( void ) const {

	if (this->brain)
		this->brain->printIdeas();
}

void	Cat::deepCopy(const Cat &src) {

	if (this != &src) {
		delete this->brain;
		if (src.brain)
			this->brain = new Brain( *(src.brain) );
		else
			this->brain = src.brain;
	}
}

