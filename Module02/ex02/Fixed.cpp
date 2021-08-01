#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value_(0) {

//	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const i) {

//	std::cout << "Int constructor called\n";
	this->value_ = i << this->fract_bits;
}

Fixed::Fixed(float const f) {

//	std::cout << "Float constructor called\n";
	this->value_ = std::roundf(f * (1 << this->fract_bits));
}

float		Fixed::toFloat( void ) const {

	return (((float)this->value_) / (1 << this->fract_bits));
}

int 		Fixed::toInt( void ) const {

	return (this->value_ >> this->fract_bits);
}

Fixed::~Fixed() {

//	std::cout << "Destructor called\n";
}

int			Fixed::getRawBits( void ) const {

//	std::cout << "getRawBits member function called\n";
	return (this->value_);
}

void		Fixed::setRawBits( int const raw ) {

//	std::cout << "setRawBits member function called\n";
	this->value_ = raw;
}

Fixed const &Fixed::operator=(Fixed const &rhs) {

//	std::cout << "Assignation operator called\n";
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

	std::cout << "Fixed &max( Fixed &a, Fixed &b ) is called\n";

	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {

	std::cout << "Fixed const &max( Fixed const &a, "
				 "Fixed const &b ) is called\n";

	if (a > b)
		return (a);
	return (b);
}

Fixed::Fixed(Fixed const &cp) {

//	std::cout << "Copy constructor called\n";
	*this = cp;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &rhs) {

	os << rhs.toFloat();
	return (os);
}
