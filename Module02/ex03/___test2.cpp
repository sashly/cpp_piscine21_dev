#include <iostream>

class Test {
public:

	Test() : x(0), y(0) {std::cout << "Default constructor called\n";};
	Test(int const ix, int const iy) : x(ix), y(iy) {
		std::cout << "Constructor called\n";};
	~Test() {std::cout << "Destructor called\n";};

	int	getx( void ) const { return(this->x); };
	int	gety( void ) const { return(this->y); };

//	Test const &operator=(Test const &rhs) {
//		std::cout << "Assigning operator called\n";
//		this->x = rhs.getx();
//		return (*this);
//	};

private:
	int	x;
	int	y;
};

std::ostream	&operator<<(std::ostream &os, Test const &rhs) {

	os << "x: " << rhs.getx() << ", y: " << rhs.gety();
	return (os);
}

int	main( void ) {

	Test	y(1, 2);
	Test	z(5, 3);
	Test	x;

	x = z = y;

	std::cout << "x --> |" << x << "|, y --> |" << y << "|, z --> |" << z << "|\n";
	return (0);
}
