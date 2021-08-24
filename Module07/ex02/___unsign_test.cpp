#include <iostream>
#include <limits>
#include <unistd.h>

void	conv_test( unsigned int const x ) {
	std::cout << "after conversion: " << x << "\n";
}

int main( void ) {
	std::cout << std::numeric_limits<unsigned int>::min() << "\n";
	std::cout << std::numeric_limits<unsigned int>::max() << "\n";
	std::cout << std::numeric_limits<int>::min() << "\n";
	std::cout << std::numeric_limits<int>::max() << "\n";

	std::cout << "\n";
	int		*arr = new int[3147483647u];
	arr[3147483645u] = 7;
	std::cout << arr[3147483645u] << "\n";

	conv_test( -2147483648 );

	(void)arr;
//	sleep( 10 );
	return ( 0 );
}

