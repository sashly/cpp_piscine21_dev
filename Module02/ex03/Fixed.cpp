#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : raw_value_( 0 ) {}

Fixed::Fixed( int const i ) {

	this->raw_value_ = (i << this->fract_bits);
}

Fixed::Fixed( float const f ) {

	this->raw_value_ = std::roundf(f * (1 << this->fract_bits));
}

Fixed::Fixed( Fixed const &src ) {

	*this = src;
}

Fixed::~Fixed( void ) {}

Fixed		&Fixed::operator=( Fixed const &rhs ) {

	this->raw_value_ = rhs.getRawBits();
	return (*this);
}

bool		Fixed::operator>( Fixed const &rhs ) const {

	return (this->getRawBits() > rhs.getRawBits());
}

bool		Fixed::operator<( Fixed const &rhs ) const {

	return (this->getRawBits() < rhs.getRawBits());
}

bool		Fixed::operator>=( Fixed const &rhs ) const {

	return (this->getRawBits() >= rhs.getRawBits());
}

bool		Fixed::operator<=( Fixed const &rhs ) const {

	return (this->getRawBits() <= rhs.getRawBits());
}

bool		Fixed::operator==( Fixed const &rhs ) const {

	return (this->getRawBits() == rhs.getRawBits());
}

bool		Fixed::operator!=( Fixed const &rhs ) const {

	return (this->getRawBits() != rhs.getRawBits());
}

Fixed		Fixed::operator+( Fixed const &rhs ) const {

	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed		Fixed::operator-( Fixed const &rhs ) const {

	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed		Fixed::operator*( Fixed const &rhs ) const {

	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed		Fixed::operator/( Fixed const &rhs ) const {

	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed		&Fixed::operator++( void ) {

	this->raw_value_ += 1;
	return (*this);
}

Fixed		Fixed::operator++( int ) {

	Fixed	ret(*this);

	++*this;
	return (ret);
}

Fixed		&Fixed::operator--( void ) {

	this->raw_value_ -= 1;
	return (*this);
}

Fixed		Fixed::operator--( int ) {

	Fixed	ret(*this);

	--*this;
	return (ret);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b ) {

	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b ) {

	if (a > b)
		return (a);
	return (b);
}

Fixed	&Fixed::min( Fixed &a, Fixed &b ) {

	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b ) {

	if (a < b)
		return (a);
	return (b);
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
