#include <iostream>

class Test {
public:
	Test( void ) { std::cout << "Default constructor called.\n"; }
	Test( Test const &src ) {
		std::cout << "Copy constructor called.\n";
		*this = src;
	}
	~Test( void ) { std::cout << "Destructor called.\n"; }

	Test	&operator=( Test const &rhs ) {

		std::cout << "Assignation operator called.\n";
		if (this != &rhs) {
			this->a = rhs.a;
		}
		return ( *this );
	}

private:
	int	a;
};

int	main( void ) {

	Test	a;
	Test	b( a );
	Test	c;
	//	c( a );   // type 'Test' does not provide a call operator

	(void)a;
	(void)b;
	return ( 0 );
}
