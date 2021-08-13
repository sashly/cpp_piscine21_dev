#include "Brain.hpp"
#include <iostream>

Brain::Brain( void ) : index( 0 ) {

	std::cout << "------> Default Brain constructor called\n";
}

Brain::Brain( Brain const &src ) {

	std::cout << "------> Brain Copy constructor called\n";
	*this = src;
}

Brain::~Brain( void ) { std::cout << "------> Brain destructor called\n"; }

Brain	&Brain::operator=( Brain const &rhs ) {

	if (this != &rhs) {
		this->index = rhs.getIndex();
		for (int i = 0; i < this->index; i++)
			this->ideas[i] = rhs.getIdea( i );
	}
	return ( *this );
}

std::string	Brain::getIdea( int index ) const {

	if (index >= this->index || index < 0)
		return ( "" );
	return ( this->ideas[index] );
}

int	Brain::getIndex( void ) const {

	return ( this->index );
}


void	Brain::setIdea( std::string const &idea ) {

	if (this->index < this->ideas_size) {
		this->ideas[this->index] = idea;
		this->index++;
	}
	else
		std::cout << "Cannot add: The ideas array is full;\n";
}

void	Brain::printIdeas( void ) const {

	std::cout << "Ideas:";
	for (int i = 0; i < this->index; i++)
		std::cout << " " << this->getIdea( i );
	std::cout << "\n";
}
