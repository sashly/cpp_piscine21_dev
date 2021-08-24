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

class Awesome {
public:
	Awesome( int n ) : _n( n ) {}
	bool operator==( Awesome const & rhs ) const {
		return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{
		return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const {
		return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const {
		return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const {
		return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const {
		return (this->_n <= rhs._n); }
	int		getN( void ) const { return ( this->_n ); }
private:
	int _n;
};

std::ostream	&operator<<( std::ostream &os, Awesome const &a ) {
	return ( os << a.getN() );
}

template<typename T>
void	swap_test( T a, T b, char const *name ) {
	T at( a ), bt( b );
	std::cout << MAGENTA << name << ":" << RESET << "\tbefore swap --> a: "
			  << at << ", b: " << bt << "\n";
	swap( at, bt );
	std::cout << "    \t after swap --> a: " << at << ", b: " << bt << "\n";
}

template<typename T>
void min_max_test( T a, T b, char const *name ) {
	T	at( a ), bt( b );
	std::cout << MAGENTA << name << ":" << RESET << "\ta: " << at
			  << " {" << (void *)&at << "}, b:" << bt << " {"
			  << (void *)&bt << "};\n";
	T const	&min = ::min( at, bt );
	std::cout << "\tmin( a, b ): " << min << " {" << (void *)&min << "};\n";
	T const	&max = ::max( at, bt );
	std::cout << "\tmax( a, b ): " << max << " {" << (void *)&max << "};\n";
}

int	main( void ) {
	{
		std::cout << GREEN << "\t--> SUBJECT TEST: <--" << RESET << "\n";
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "\n";
		std::cout << GREEN << "\t--> SWAP TESTS: <--" << RESET << "\n";
		swap_test( 5, -1, "Int" );
		swap_test( -5.23f, .023f, "Float" );
		swap_test( '!', '*', "Char" );
		swap_test( 5.123, -1. / 0., "Double" );
		swap_test( "hello", "world", "String" );
		swap_test<Awesome>( 11, 3, "Class" );
	}
	{
		std::cout << "\n";
		std::cout << GREEN <<"\t--> MIN/MAX TESTS: <--" << RESET << "\n";
		min_max_test( 5, 3, "Int" );
		min_max_test( 7, 7, "Int" );
		min_max_test( 234.124f, -123.1001f, "Float" );
		min_max_test( 0.012435, 0.01243, "Double" );
		min_max_test( '0', '1', "Char" );
		min_max_test<std::string>( "hello2", "hello1", "String" );
		min_max_test<Awesome>( 123, 432, "Class" );
	}

	return ( 0 );
}

