#include <iostream>
#include <exception>
#include <cstdlib>
#include "Bureaucrat.hpp"

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

void	my_unexpected( void ) {

	std::cout << "unexpected exception thrown\n";
	std::exit( 1 );
}

int	main( void ) {

	std::set_unexpected( &my_unexpected );

	try {
		std::cout << GREEN
				  << "       --> CONSTRUCT WITH TOO HIGH GRADE <--\n" << RESET;
		Bureaucrat	bob( "Bob", 0 );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << GREEN
		<< "       --> CONSTRUCT WITH TOO LOW GRADE <--\n" << RESET;
		Bureaucrat	tom( "Tom", 151 );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << GREEN
				  << "       --> GRADE IS TOO HIGH TO INC <--\n" << RESET;
		Bureaucrat	john( "John", 3 );
		std::cout << john << "\n";
		john.incGrade();
		std::cout << john << "\n";
		john.incGrade();
		std::cout << john << "\n";
		john.incGrade();
		std::cout << john << "\n";
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << GREEN
				  << "       --> GRADE IS TOO LOW TO DEC <--\n" << RESET;
		Bureaucrat	rick( "Rick", 149 );
		std::cout << rick << "\n";
		rick.decGrade();
		std::cout << rick << "\n";
		rick.decGrade();
		std::cout << rick << "\n";
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}
	return ( 0 );
}
