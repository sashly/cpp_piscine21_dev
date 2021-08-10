#include <iostream>
#include <string>

class Test {
public:
	Test( void ) {}
	Test( Test const &src ) {

		*this = src;
	}
	~Test( void ) {}
	Test	&operator=( Test const &rhs) {

		if ( this != &rhs ) {
			for (int i = 0; i < 5; ++i)
				this->arr[i] = rhs.arr[i];
		}
		return ( *this );
	}

	void	print( void ) {

		std::cout << "arr:";
		for (int i = 0; i < 5; i++)
			std::cout << " " << this->arr[i];
		std::cout << "\n";
	}

	std::string	arr[5];
};

int	main( void ) {

	Test	test;

	test.arr[0] = "hello";
	test.arr[1] = "world";
	test.arr[2] = "!";
	test.arr[3] = ".";
	test.arr[4] = ".";

	test.print();

	Test	copy( test );
	copy.print();

	Test	assign;
	assign = test;
	assign.print();

	return ( 0 );
}
