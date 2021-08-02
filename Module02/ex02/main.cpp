#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

#define FW	19

int main( void ) {

	{
		std::cout << "             --->> SUBJECT TESTS <<---\n";

		Fixed 		a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << "            " << a << std::endl;
		std::cout << "            " << ++a << std::endl;
		std::cout << "            " << a << std::endl;
		std::cout << "            " << a++ << std::endl;
		std::cout << "            " << a << std::endl;

		std::cout << "            " << b << std::endl;

		std::cout << "            " << Fixed::max(a, b) << std::endl;
	}

	{
		Fixed	tmp;
		Fixed	x(17.321f);
		Fixed	y(23.012f);
		Fixed	x1(2.123f);
		Fixed	y1(2.123f);

		std::cout << "\n";
		std::cout << "     --->> COMPARISON OPERATOR OVERLOAD <<---\n";
		std::cout << std::setw(FW) << x << " < " << y << std::setw(9)
				  << "   --> "
				  << std::boolalpha << (x < y) << "\n";
		std::cout << std::setw(FW) << x << " > " << y << std::setw(9)
				  << "   --> "
				  << std::boolalpha << (x > y) << "\n";
		std::cout << std::setw(FW) << x << " <= " << y << std::setw(8)
				  << "   --> "
				  << std::boolalpha << (x <= y) << "\n";
		std::cout << std::setw(FW) << x << " >= " << y << std::setw(8)
				  << "   --> "
				  << std::boolalpha << (x >= y) << "\n";
		std::cout << std::setw(FW) << x << " == " << y << std::setw(8)
				  << "   --> "
				  << std::boolalpha << (x == y) << "\n";
		std::cout << std::setw(FW) << x1 << " == " << y1 << std::setw(8)
				  << "   --> " << std::boolalpha << (x1 == y1) << "\n";
		std::cout << std::setw(FW) << x << " != " << y << std::setw(8)
				  << "   --> "
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
		tmp = y / x;
		std::cout << std::setw(FW) << y << " / " << x << " = " << tmp << "\n";
//		tmp = y / Fixed();
//		std::cout << std::setw(FW) << y << " / " << Fixed() << " = " << tmp << "\n";
		std::cout << "\n";

		std::cout << "         --->> CHAINING ASSIGNMENT <<---\n";
		std::cout << "     " << "x: " << x << ", y: " << y << ", x1: "
				  << x1 << ", y1: " << y1 << "\n"
				  << "                    " << "x = y = x1 = y1;\n";
		x = y = x1 = y1;
		std::cout << "     " << "x: " << x << ", y: " << y << ", x1: "
				  << x1 << ", y1: " << y1 << "\n";
		std::cout << "\n";
	}
	{
		Fixed	a;
		Fixed	b( 1.123f );
		Fixed	c;
		Fixed	d( 123.5f );

		std::cout << "     --->> INCREMENT/DECREMENT OVERLOAD <<---\n";
		std::cout << "            " << "      a++: " << a++ << "\n";
		std::cout << "            " << "after a++: " << a << "\n";
		std::cout << "            " << "      b++: " << b++ << "\n";
		std::cout << "            " << "after b++: " << b << "\n";
		std::cout << "            " << "      ++a: " << ++a << "\n";
		std::cout << "            " << "after ++a: " << a << "\n";

		std::cout << "            " << "      c--: " << c-- << "\n";
		std::cout << "            " << "after c--: " << c << "\n";
		std::cout << "            " << "      d--: " << d-- << "\n";
		std::cout << "            " << "after d--: " << d << "\n";
		std::cout << "            " << "      --c: " << --c << "\n";
		std::cout << "            " << "after --c: " << c << "\n";
		std::cout << "\n";
	}
	{
		Fixed		a( -12.412f );
		Fixed		b( 7.412f );
		Fixed const	c( -21.412f );
		Fixed const d( 4112.412f );

		std::cout << "      --->> MAX/MIN FUNCTIONS OVERLOAD <<---\n";
		std::cout << "          " << "a = " << a << ", b = " << b << ";\n";
		std::cout << "          " << "max( a, b ) --> "
				  << Fixed::max(a, b) << "\n          " << "min( a, b ) --> "
				  << Fixed::min(a, b) << "\n";
		std::cout << "          " << "c = " << c << ", d = " << d << ";\n";
		std::cout << "          " << "max( c, d ) --> "
				  << Fixed::max(c, d) << "\n          " << "min( c, d ) --> "
				  << Fixed::min(c, d) << "\n";
	}

	return (0);
}
