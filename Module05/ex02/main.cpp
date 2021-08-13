#include <iostream>
#include <exception>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

	Form	*f1;

	try {
		std::cout << GREEN
				  << "       --> SHRUBBERY FORM TESTS: <--" << RESET << "\n";
		f1 = new ShrubberyCreationForm( "Bob" );
		Bureaucrat	bob( "Bob", 5 );
		bob.signForm( *f1 );
		f1->execute( bob );
		delete f1;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
		delete f1;
	}
	try {
		std::cout << GREEN
				  << "       --> ROBOTO FORM TESTS: <--" << RESET << "\n";
		f1 = new RobotomyRequestForm( "Bob" );
		Bureaucrat	bob( "Bob", 5 );
		bob.signForm( *f1 );
		f1->execute( bob );
		delete f1;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
		delete f1;
	}
	try {
		std::cout << GREEN
				  << "       --> PRESIDENTIAL FORM TESTS: <--" << RESET << "\n";
		f1 = new PresidentialPardonForm( "Bob" );
		Bureaucrat	bob( "Bob", 5 );
		bob.signForm( *f1 );
		f1->execute( bob );
		delete f1;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
		delete f1;
	}
	try {
		std::cout << GREEN
				  << "       --> SIGN & EXEC FORM TESTS: <--" << RESET << "\n";
		f1 = new PresidentialPardonForm( "Bob" );
		Bureaucrat	bob( "Bob", 5 );
		f1->execute( bob );
		bob.signForm( *f1 );
		delete f1;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
		delete f1;
	}
	try {
		std::cout << GREEN
				  << "       --> SIGN & EXEC FORM TESTS: <--" << RESET << "\n";
		f1 = new PresidentialPardonForm( "Bob" );
		Bureaucrat	bob( "Bob", 25 );
		bob.signForm( *f1 );
		f1->execute( bob );
		delete f1;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
		delete f1;
	}
	try {
		std::cout << GREEN
		<< "       --> BUREAUCRAT SIGNING A FORM <--\n" << RESET;
		Bureaucrat	john( "John", 11 );
		Bureaucrat	bob( "Bob", 5 );
		Bureaucrat	tom( "Tom", 25 );
		PresidentialPardonForm	form1( "target1" );
		RobotomyRequestForm		form2( "target2" );
		ShrubberyCreationForm	form3( "Bob" );

		std::cout << form1 << "\n";
		std::cout << form2 << "\n";
		tom.executeForm( form1 );
		john.signForm( form1 );
		bob.signForm( form2 );
		tom.signForm( form1 );
		tom.executeForm( form1 );
		tom.executeForm( form2 );
		tom.signForm( form3 );
		tom.executeForm( form3 );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
	}


	return ( 0 );
}
