#include <iostream>

class Test {
public:
	Test( void ) { std::cout << "default constructor is called;\n"; }
private:
};

int	main( void ) {
	{
		int *a = new int();
		std::cout << "*a = " << *a << "\n";
		delete a;
	}
	{
		Test *a = new Test[11]();
//		std::cout << "arr: ";
//		for (int i = 0; i < 11; i++)
//			std::cout << " " << a[i];
//		std::cout << "\n";
		(void)a;
	}
{
	int size = 100;
	int *a = new int[size]();
	std::cout << "arr: ";
	for (int i = 0; i < size; i++)
		std::cout << " " << a[i];
	std::cout << "\n";
}

	return ( 0 );
}

