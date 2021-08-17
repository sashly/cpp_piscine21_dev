#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

class Base {
public:
	virtual ~Base( void ) {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate( void );
void	identify( Base* p );
void	identify( Base &p );

int	main( void ) {

	Base	*bp;

	bp = generate();
	std::cout << GREEN <<"\t--> Identify by pointer: <--" << RESET << "\n";
	identify( bp );
	std::cout << GREEN <<"\t--> Identify by reference: <--" << RESET << "\n";
	identify( *bp );

	delete bp;
	return ( 0 );
}

Base	*generate( void ) {

	std::srand( std::time( 0 ) );
	switch ( rand() % 3 )
	{
		case 0: return ( new A );
		case 1: return ( new B );
		case 2: return ( new C );
	}
	return ( 0 );
}

void	identify( Base* p ) {

	A	*ap = dynamic_cast<A *>( p );
	if (ap)
		std::cout << "It is A type.\n";
	B	*bp = dynamic_cast<B *>( p );
	if (bp)
		std::cout << "It is B type.\n";
	C	*cp = dynamic_cast<C *>( p );
	if (cp)
		std::cout << "It is C type.\n";
}

void	identify( Base &p ) {

	try {
		A	&ar = dynamic_cast<A &>( p );
		std::cout << "It is A type.\n";
	}
	catch (...) {}
	try {
		B	&br = dynamic_cast<B &>( p );
		std::cout << "It is B type.\n";
	}
	catch (...) {}
	try {
		C	&cr = dynamic_cast<C &>( p );
		std::cout << "It is C type.\n";
	}
	catch (...) {}
}
