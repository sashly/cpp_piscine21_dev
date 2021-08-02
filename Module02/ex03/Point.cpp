#include "Point.hpp"

Point::Point( void ) : x(), y() {}

Point::Point( float const fx, float const fy ) : x( fx ), y( fy ) {}

Point::Point( Point const &src ) : x( src.getx() ), y( src.gety() ) {}

Point::~Point( void ) {}

Point		&Point::operator=( Point const &rhs ) {

	(void)rhs;
	return (*this);
}

Fixed const	&Point::getx( void ) const {

	return (this->x);
}

Fixed const	&Point::gety( void ) const {

	return (this->y);
}

std::ostream	&operator<<( std::ostream &os, Point const &rhs ) {

	os << "{" << rhs.getx() << ", " << rhs.gety() << "}";
	return (os);
}
