#include <iostream>

class A {
public:
	A( void ) { std::cout << "A constructor is called!\n"; }
	~A( void ) { std::cout << "A destructor is called!\n"; }
	int a;
};

class B : public virtual A {
public:
	B( void ) { std::cout << "B constructor is called!\n"; }
	~B( void ) { std::cout << "B destructor is called!\n"; }
	int b;
};

class C : public virtual A {
public:
	C( void ) { std::cout << "C constructor is called!\n"; }
	~C( void ) { std::cout << "C destructor is called!\n"; }
	int c;
};

class D : public B, public C {
public:
	D( void ) { std::cout << "D constructor is called!\n"; }
	~D( void ) { std::cout << "D destructor is called!\n"; }
	int d;
};

int	main( void ) {

	D test;

	return (0);
}
