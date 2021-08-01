#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value_(0) {

	std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {

	std::cout << "Destructor called\n";
}

int			Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called\n";
	return (this->value_);
}

void		Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called\n";
	this->value_ = raw;
}

Fixed const &Fixed::operator=(Fixed const &rhs) {

	std::cout << "Assignation operator called\n";
	this->value_ = rhs.getRawBits();
	return (*this);
}

Fixed::Fixed(Fixed const &cp) {

	std::cout << "Copy constructor called\n";
	*this = cp;
}
