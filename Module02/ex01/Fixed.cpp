#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : raw_value_( 0 ) {

	std::cout << "Default constructor called\n";
}

Fixed::Fixed( int const i ) {

	std::cout << "Int constructor called\n";
	this->raw_value_ = (i << this->fract_bits);
}

Fixed::Fixed( float const f ) {

	std::cout << "Float constructor called\n";
	this->raw_value_ = std::roundf(f * (1 << this->fract_bits));
}

Fixed::Fixed( Fixed const &src ) {

	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called\n";
}

Fixed	&Fixed::operator=( Fixed const &rhs ) {

	std::cout << "Assignation operator called\n";
	this->raw_value_ = rhs.getRawBits();
	return (*this);
}

int			Fixed::getRawBits( void ) const {

	return (this->raw_value_);
}

void		Fixed::setRawBits( int const raw ) {

	this->raw_value_ = raw;
}

float		Fixed::toFloat( void ) const {

	return (((float)this->raw_value_) / ((float)(1 << this->fract_bits)));
}

int 		Fixed::toInt( void ) const {

	return (this->raw_value_ >> this->fract_bits);
}

std::ostream	&operator<<( std::ostream &os, Fixed const &rhs ) {

	os << rhs.toFloat();
	return (os);
}
