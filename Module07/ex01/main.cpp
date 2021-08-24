#include "Iter.hpp"
#include <iostream>

class Awesome {
public:
	Awesome( void ) : _n( 42 ) { return; }
	int	get( void ) const { return this->_n; }
private:
	int	_n;
};

std::ostream	&operator<<( std::ostream &o, Awesome const &rhs ) {
	o << rhs.get();
	return o;
}

template< typename T >
void print( T const &x ) { std::cout << x << std::endl; return; }

void	mult2( int &x ) { x *= 2; }
void	div2( int &x ) { x /= 2; }

template<typename A>
void	f( A const &a ) {
	std::cout << " " << a;
}

int	main( void ) {
	{
		std::cout << GREEN << "\t--> SUBJECT TEST: <--" << RESET << "\n";
		int tab[] = { 0, 1, 2, 3, 4 };
		Awesome tab2[5];
		iter( tab, 5, print );
		iter( tab2, 5, print );
	}
	{
		std::cout << "\n";
		std::cout << GREEN << "\t--> SOME TESTS: <--" << RESET << "\n";
		int arr[5] = {1, 43, -4, 4, 71};
		std::cout << "arr:";
		iter(arr, 5, &f);
		std::cout << "\n";
		iter(arr, 5, &mult2);
		std::cout << "arr:";
		iter(arr, 5, &f);
		std::cout << "\n";
		iter(arr, 5, &div2);
		std::cout << "arr:";
		iter(arr, 5, &f);
		std::cout << "\n";
	}

	return ( 0 );
}
