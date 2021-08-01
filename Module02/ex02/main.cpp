#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

#define FW	19

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;


	Fixed	tmp;
	Fixed	x( 17.321f );
	Fixed	y( 23.012f );
	Fixed	x1( 2.123f );
	Fixed	y1( 2.123f );

	std::cout << "\n";
	std::cout << "     --->> COMPARISON OPERATOR OVERLOAD <<---\n";
	std::cout << std::setw(FW) << x << " < " << y << std::setw(9) << "   --> "
			  << std::boolalpha << (x < y) << "\n";
	std::cout << std::setw(FW) << x << " > " << y << std::setw(9) << "   --> "
			  << std::boolalpha << (x > y) << "\n";
	std::cout << std::setw(FW) << x << " <= " << y << std::setw(8) << "   --> "
			  << std::boolalpha << (x <= y) << "\n";
	std::cout << std::setw(FW) << x << " >= " << y << std::setw(8) << "   --> "
			  << std::boolalpha << (x >= y) << "\n";
	std::cout << std::setw(FW) << x << " == " << y << std::setw(8) << "   --> "
			  << std::boolalpha << (x == y) << "\n";
	std::cout << std::setw(FW) << x1 << " == " << y1 << std::setw(8)
			  << "   --> " << std::boolalpha << (x1 == y1) << "\n";
	std::cout << std::setw(FW) << x << " != " << y << std::setw(8) << "   --> "
			  << std::boolalpha << (x != y) << "\n";
	std::cout << std::setw(FW) << x1 << " != " << y1 << std::setw(8)
			  << "   --> " << std::boolalpha << (x1 != y1) << "\n";
	std::cout << "\n";
	std::cout << "     --->> ARITHMETIC OPERATOR OVERLOAD <<---\n";
	tmp = x + y;
	std::cout << std::setw(FW) << x << " + " << y << " = " << tmp << "\n";
	tmp = x - y;
	std::cout << std::setw(FW) << x << " - " << y << " = " << tmp << "\n";
	tmp = x * y;
	std::cout << std::setw(FW) << x << " * " << y << " = " << tmp << "\n";
	tmp = x / y;
	std::cout << std::setw(FW) << x << " / " << y << " = " << tmp << "\n";

	Fixed a1;
	Fixed const b1( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a1 << std::endl;
	std::cout << ++a1 << std::endl;
	std::cout << a1 << std::endl;
	std::cout << a1++ << std::endl;
	std::cout << a1 << std::endl;
	std::cout << b1 << std::endl;

	std::cout << Fixed::max( a1, b1 ) << std::endl;

	std::cout << "\n";
	return (0);
}
