#include "Iter.hpp"
#include <iostream>

void	mult2( int *x ) { *x *= 2; }
void	mult3( int *x ) { *x *= 3; }

template<typename A>
void	f( A a ) {
	std::cout << " " << a;
}

int	main( void ) {

	int	arr[5] = { 1, 43, -4, 4, 71 };
	std::cout << "arr:";
	iter( arr, 5, &f );
	std::cout << "\n";

	return ( 0 );
}
