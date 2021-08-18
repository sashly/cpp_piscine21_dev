#include <iostream>
#include <cstdint>
#include "Data.hpp"

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

uintptr_t	serialize( Data* ptr ) {

	return ( reinterpret_cast<uintptr_t>( ptr ) );
}

Data*		deserialize( uintptr_t raw ) {

	return ( reinterpret_cast<Data *>( raw ) );
}

int main( void ) {

	Data	d1;
	Data	d2( 5 );

	std::cout << "d1 { ptr: " << &d1 << ", d1.val: " << d1.getVal() << " }\n";
	std::cout << "d2 { ptr: " << &d2 << ", d2.val: " << d2.getVal() << " }\n";
	d1.hello();
	d2.hello();

	std::cout << GREEN <<"\n\t\t--> SERIALIZATION: <--" << RESET << "\n";
	uintptr_t tmp1 = serialize( &d1 );
	std::cout << "&d1 serialize (raw value): " << tmp1 << "\n";
	uintptr_t tmp2 = serialize( &d2 );
	std::cout << "&d2 serialize (raw value): " << tmp2 << "\n";

	std::cout << GREEN <<"\n\t\t--> DESERIALIZATION: <--" << RESET << "\n";
	Data	*dp = deserialize( tmp1 );
	std::cout << "d1 { ptr: " << dp << ", d1.val: " << dp->getVal() << " }\n";
	dp->hello();
	dp = deserialize( tmp2 );
	std::cout << "d2 { ptr: " << dp << ", d2.val: " << dp->getVal() << " }\n";
	dp->hello();

	return ( 0 );
}
