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
				  << "       --> FORM CONSTRUCTION EXCEPTIONS <--\n" << RESET;
		Form	form1( "form1", -1, 10 );
//		Form	form2( "form2", 10, -1 );
//		Form	form3( "form3", 200, 1 );
//		Form	form4( "form4", 200, 1 );
//		Form	form5( "form5", 0, 200);
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << GREEN
		<< "       --> FORM SIGNING EXCEPTIONS <--\n" << RESET;
		Form	form1( "form1", 10, 15 );
		Bureaucrat	john( "John", 11 );
		std::cout << john << "\n";
		std::cout << form1 << "\n";
		form1.beSigned( john );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << GREEN
		<< "       --> FORM SIGNING EXCEPTIONS <--\n" << RESET;
		Form	form1( "form1", 10, 15 );
		Bureaucrat	john( "John", 10 );
		std::cout << john << "\n";
		std::cout << form1 << "\n";
		form1.beSigned( john );
		std::cout << form1 << "\n";
		form1.beSigned( john );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << GREEN
		<< "       --> BUREAUCRAT SIGNING A FORM <--\n" << RESET;
		Bureaucrat	john( "John", 11 );
		Bureaucrat	bob( "Bob", 5 );
		Bureaucrat	tom( "Tom", 5 );
		Form		form( "form", 10, 15 );

		std::cout << form << "\n";
		john.signForm( form );
		bob.signForm( form );
		tom.signForm( form );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}

	return ( 0 );
}
