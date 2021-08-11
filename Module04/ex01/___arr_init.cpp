#include <iostream>

class I {
public:
	I( void ) { std::cout << "I default constructor is called.\n"; }
	~I( void ) { std::cout << "I destructor is called.\n"; }
private:
	int a;
};

class O {
public:
	O( void ) { std::cout << "O default constructor is called.\n"; }
	~O( void ) { std::cout << "O destructor is called.\n"; }
private:
	I	arr[5];
};

int	main( void ) {

	O	n;

	(void)n;
	return ( 0 );
}
