#include "Brain.hpp"
#include <iostream>

Brain::Brain( void ) : index( 0 ) {}

Brain::Brain( Brain const &src ) {

	*this = src;
}

Brain::~Brain( void ) {}

Brain	&Brain::operator=( Brain const &rhs ) {

	if ( this != &rhs ) {
		this->index = rhs.index;
		for ( int i = 0; i < this->index; i++ )
			this->ideas[i] = rhs.ideas[i];
	}
	return ( *this );
}

std::string	Brain::getIdea( int index ) const {

	if ( index > this->index || index < 0 )
		return ( "" );
	return ( this->ideas[index] );
}

void	Brain::setIdea( std::string const &idea ) {

	if ( this->index < this->ideas_size ) {
		this->ideas[this->index] = idea;
		this->index++;
	}
	else
		std::cout << "Cannot add: The ideas array is full;\n";
}

void	Brain::printIdeas( void ) const {

	std::cout << "Ideas:";
	for (int i = 0; i < this->index; i++)
		std::cout << " " << this->ideas[i];
	std::cout << "\n";
}
