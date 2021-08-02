#include "Point.hpp"
#include <iostream>

int	main( void ) {

	{
		Point p1(431.2f, 107.1f);
		Point p2(158.2f, 288.f);
		Point p3(138.23f, 89.f);
		Point p(232.21f, 157.60f);

		std::cout << "p1 --> " << p1 << ", "
		<< "p2 --> " << p2 << ", "
		<< "p3 --> " << p3 << ", "
		<< "p --> " << p << ";\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		Point p1(431.2f, 107.1f);
		Point p2(158.2f, 288.f);
		Point p3(138.23f, 89.f);
		Point p(184.321f, 228.24f);

		std::cout << "p1 --> " << p1 << ", "
		<< "p2 --> " << p2 << ", "
		<< "p3 --> " << p3 << ", "
		<< "p --> " << p << ";\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		Point p1(431.2f, 107.1f);
		Point p2(158.2f, 288.f);
		Point p3(138.23f, 89.f);
		Point p(386.f, 118.53f);

		std::cout << "p1 --> " << p1 << ", "
		<< "p2 --> " << p2 << ", "
		<< "p3 --> " << p3 << ", "
		<< "p --> " << p << ";\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		Point p1(431.2f, 107.1f);
		Point p2(158.2f, 288.f);
		Point p3(138.23f, 89.f);
		Point p(295.1f, 68.3f);

		std::cout << "p1 --> " << p1 << ", "
		<< "p2 --> " << p2 << ", "
		<< "p3 --> " << p3 << ", "
		<< "p --> " << p << ";\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}
	{
		Point p1(431.2f, 107.1f);
		Point p2(158.2f, 288.f);
		Point p3(138.23f, 89.f);
		Point p(126.5f, 206.60f);

		std::cout << "p1 --> " << p1 << ", "
		<< "p2 --> " << p2 << ", "
		<< "p3 --> " << p3 << ", "
		<< "p --> " << p << ";\n";
		std::cout << "The point p is inside the triangle? --> "
		<< std::boolalpha
		<< bsp(p1, p2, p3, p) << "\n\n";
	}

	return (0);
}
