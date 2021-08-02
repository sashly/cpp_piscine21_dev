#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(int const i) {

	this->value_ = i << this->fract_bits;
}

Fixed::Fixed(float const f) {

	this->value_ = std::roundf(f * (1 << this->fract_bits));
}

float		Fixed::toFloat( void ) const {

	return (((float)this->value_) / (1 << this->fract_bits));
}

int 		Fixed::toInt( void ) const {

	return (this->value_ >> this->fract_bits);
}

Fixed::~Fixed() {}

int			Fixed::getRawBits( void ) const {

	return (this->value_);
}

void		Fixed::setRawBits( int const raw ) {

	this->value_ = raw;
}

Fixed const &Fixed::operator=(Fixed const &rhs) {

	this->value_ = rhs.getRawBits();
	return (*this);
}

bool		Fixed::operator>(Fixed const &rhs) const {

	return (this->getRawBits() > rhs.getRawBits());
}

bool		Fixed::operator<(Fixed const &rhs) const {

	return (this->getRawBits() < rhs.getRawBits());
}

bool		Fixed::operator>=(Fixed const &rhs) const {

	return (this->getRawBits() >= rhs.getRawBits());
}

bool		Fixed::operator<=(Fixed const &rhs) const {

	return (this->getRawBits() <= rhs.getRawBits());
}

bool		Fixed::operator==(Fixed const &rhs) const {

	return (this->getRawBits() == rhs.getRawBits());
}

bool		Fixed::operator!=(Fixed const &rhs) const {

	return (this->getRawBits() != rhs.getRawBits());
}

Fixed		Fixed::operator+(Fixed const &rhs) const {

	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed		Fixed::operator-(Fixed const &rhs) const {

	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed		Fixed::operator*(Fixed const &rhs) const {

	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed		Fixed::operator/(Fixed const &rhs) const {

	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed const	&Fixed::operator++() {

	this->value_ += 1;
	return (*this);
}

Fixed const	Fixed::operator++(int) {

	Fixed	ret(*this);

	this->value_ += 1;
	return (ret);
}

Fixed const	&Fixed::operator--() {

	this->value_ -= 1;
	return (*this);
}

Fixed const	Fixed::operator--(int) {

	Fixed	ret(*this);

	this->value_ -= 1;
	return (*this);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {

	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {

	if (a > b)
		return (a);
	return (b);
}

Fixed::Fixed(Fixed const &cp) {

	*this = cp;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &rhs) {

	os << rhs.toFloat();
	return (os);
}
