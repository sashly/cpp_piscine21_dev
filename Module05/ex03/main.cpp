#include <iostream>
#include <exception>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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

	Bureaucrat	bob( "Bob", 15 );
	Intern		SomeRandomIntern;
	Form		*f1;

	try	{
		f1 = SomeRandomIntern.makeForm( "robotomy request", "Bender" );
		if ( f1 ) {
			bob.signForm( *f1 );
			bob.executeForm( *f1 );
			delete f1;
		}
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << "\n";
		delete f1;
	}

	return ( 0 );
}
