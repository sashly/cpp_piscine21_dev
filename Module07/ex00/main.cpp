#include "whatever.hpp"
#include <iostream>

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

class Test {
public:
	Test( int id = 0 ) : id_( id ) {}
	Test( Test const &src ) : id_( src.getId() ) {}
	int 	getId( void ) const { return ( this->id_ ); }
private:
	int	id_;
};

int	main( void ) {

	std::cout << GREEN <<"\t--> SWAP TESTS: <--" << RESET << "\n";
	int i1 = 5, i2 = -1;
	std::cout << "Int:\tbefore swap --> a: " << i1 << ", b: " << i2 << "\n";
	swap<int>( &i1, &i2 );
	std::cout << "    \t after swap --> a: " << i1 << ", b: " << i2 << "\n";
	float f1 = -5.23f, f2 = .023f;
	std::cout << "Float:\tbefore swap --> a: " << f1 << ", b: " << f2 << "\n";
	swap<float>( &f1, &f2 );
	std::cout << "      \t after swap --> a: " << f1 << ", b: " << f2 << "\n";
	char	c1 = '!', c2 = '*';
	std::cout << "Char:\tbefore swap --> a: " << c1 << ", b: " << c2 << "\n";
	swap<char>( &c1, &c2 );
	std::cout << "     \t after swap --> a: " << c1 << ", b: " << c2 << "\n";
	double d1 = 5.123, d2 = -1. / 0.;
	std::cout << "Double:\tbefore swap --> a: " << d1 << ", b: " << d2 << "\n";
	swap<double>( &d1, &d2 );
	std::cout << "       \t after swap --> a: " << d1 << ", b: " << d2 << "\n";
	std::string	s1( "hello" ), s2( "world" );
	std::cout << "String:\tbefore swap --> a: " << s1 << ", b: " << s2 << "\n";
	swap<std::string>( &s1, &s2 );
	std::cout << "       \t after swap --> a: " << s1 << ", b: " << s2 << "\n";
	Test	cl1( 11 ), cl2( 3 );
	std::cout << "Class:\tbefore swap --> a: " << cl1.getId()
			  << ", b: " << cl2.getId() << "\n";
	swap<Test>( &cl1, &cl2 );
	std::cout << "       \t after swap --> a: " << cl1.getId()
			  << ", b: " << cl2.getId() << "\n";

	std::cout << GREEN <<"\t--> MIN TESTS: <--" << RESET << "\n";
	std::cout << GREEN <<"\t--> MAX TESTS: <--" << RESET << "\n";
	return ( 0 );
}
