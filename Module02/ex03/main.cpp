#include "Point.hpp"
#include <iostream>

int	main( void ) {

	{
		std::cout << "       --->> CASE-00 <<---\n";
		Point const p1( 431.2f, 107.1f );
		Point const p2( 158.2f, 288.f );
		Point const p3( 138.23f, 89.f );
		Point const p( 213.21f, 188.60f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
				  << std::boolalpha
				  << bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		std::cout << "       --->> CASE-01 <<---\n";
		Point p1( 431.2f, 107.1f );
		Point p2( 158.2f, 288.f );
		Point p3( 138.23f, 89.f );
		Point p( 359.1f, 124.60f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		std::cout << "       --->> CASE-02 <<---\n";
		Point p1( 431.2f, 107.1f );
		Point p2( 158.2f, 288.f );
		Point p3( 138.23f, 89.f );
		Point p( 204.f, 160.60f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		std::cout << "       --->> CASE-03 <<---\n";
		Point p1( 431.2f, 107.1f );
		Point p2( 158.2f, 288.f );
		Point p3( 138.23f, 89.f );
		Point p( 323.f, 42.60f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		std::cout << "       --->> CASE-04 <<---\n";
		Point p1( 431.2f, 107.1f );
		Point p2( 158.2f, 288.f );
		Point p3( 138.23f, 89.f );
		Point p( 329.f, 218.60f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		std::cout << "       --->> CASE-05 <<---\n";
		Point p1( 431.2f, 107.1f );
		Point p2( 158.2f, 288.f );
		Point p3( 138.23f, 89.f );
		Point p( 126.f, 206.60f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		std::cout << "       --->> CASE-06 <<---\n";
		Point p1( 431.2f, 107.1f );
		Point p2( 158.2f, 288.f );
		Point p3( 138.23f, 89.f );
		Point p( 284.f, 93.60f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		std::cout << "       --->> CASE-07 <<---\n";
		Point p1( 431.2f, 107.1f );
		Point p2( 158.2f, 288.f );
		Point p3( 138.23f, 89.f );
		Point p( 158.2f, 288.f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		std::cout << "       --->> CASE-08 <<---\n";
		Point p1( 431.2f, 107.1f );
		Point p2( 158.2f, 288.f );
		Point p3( 138.23f, 89.f );
		Point p( 138.23f, 89.f );

		std::cout << "p1 --> " << p1 << "\n"
		<< "p2 --> " << p2 << "\n"
		<< "p3 --> " << p3 << "\n"
		<< "p  --> " << p << "\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n";
	}

	return (0);
}
