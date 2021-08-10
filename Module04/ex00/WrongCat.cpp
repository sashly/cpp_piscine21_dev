#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal() {
	this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal( src ) {}

WrongCat::~WrongCat( void ) {}

WrongCat	&WrongCat::operator=( WrongCat const &rhs ) {

	if (this != &rhs) {
		this->WrongAnimal::operator=( rhs );
	}
	return (*this);
}

void	WrongCat::makeSound( void ) const {

	std::cout << "meow meow meow...\n";
}
