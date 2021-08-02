#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : raw_value_( 0 ) {

	std::cout << "Default constructor called\n";
}

Fixed::Fixed( Fixed const &src ) {

	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called\n";
}

Fixed		&Fixed::operator=( Fixed const &rhs ) {

	std::cout << "Assignation operator called\n";
	this->raw_value_ = rhs.getRawBits();
	return (*this);
}

int			Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called\n";
	return (this->raw_value_);
}

void		Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called\n";
	this->raw_value_ = raw;
}
