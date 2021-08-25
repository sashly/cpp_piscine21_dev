#include <iostream>
#include <set>

int main( void ) {

	std::multiset<int>	ms;

	ms.insert( 3 );
	ms.insert( 421 );
	ms.insert( -321 );
	ms.insert( 132 );


	for (std::multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
		std::cout << *it << "\n";
	return ( 0 );
}

