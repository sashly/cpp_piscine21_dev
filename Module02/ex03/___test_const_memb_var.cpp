#include <iostream>

class Test {
public:

	Test() : x(0), y(0) {};
	Test(int const ix, int const iy) : x(ix), y(iy) {};
	~Test() {};

	void test(int const tx, int const ty) { this->x = tx; this->y = ty; }

private:
	int const	x;
	int const	y;
};


int	main( void ) {

	Test	t1;

	t1.test(5, 4);

	return (0);
}
