#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point {
public:

	Point( void );
	Point(float const fx, float const fy);
	~Point( void );
	Point(Point const &cp);

	Fixed const	&getx( void ) const;
	Fixed const	&gety( void ) const;

	Point const	&operator=(Point const &rhs);

private:

	Fixed	x;
	Fixed	y;
};

std::ostream	&operator<<(std::ostream &os, Point const &rhs);

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
