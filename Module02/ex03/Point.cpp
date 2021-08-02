#include "Point.hpp"

Point::Point() : x(), y() {}

Point::Point(float const fx, float const fy) : x(fx), y(fy) {}

Point::~Point() {}

Fixed const	&Point::getx( void ) const {

	return (this->x);
}

Fixed const	&Point::gety( void ) const {

	return (this->y);
}

Point const	&Point::operator=(Point const &rhs) {

	this->x = rhs.x;
	this->y = rhs.y;
	return (*this);
}

Point::Point(Point const &cp) {

	*this = cp;
}

std::ostream	&operator<<(std::ostream &os, Point const &rhs) {

	os << "{" << rhs.getx() << ", " << rhs.gety() << "}";
	return (os);
}
