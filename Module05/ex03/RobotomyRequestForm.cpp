#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( void )
		: Form( "RobotomyRequestForm", 72, 45 ), target( "" ) {}

RobotomyRequestForm::RobotomyRequestForm( std::string const &t )
		: Form( "RobotomyRequestForm", 72, 45 ), target( t ) {}

RobotomyRequestForm::RobotomyRequestForm(
				RobotomyRequestForm const &src ) : Form( src ),
												   target( src.getTarget() ) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(
							RobotomyRequestForm const &rhs ) {

	(void)rhs;
	return (*this);
}

std::string const	&RobotomyRequestForm::getTarget( void ) const {

	return ( this->target );
}

void	RobotomyRequestForm::action( void ) const {

	std::srand( std::time( 0 ) );
	std::cout << "bzzbzbbzbzbzbzbzzzz...\n";
	if (std::rand() % 2)
		std::cout << this->getTarget()
				  << " has been robotomized successfully.\n";
	else
		std::cout << "It's failure.\n";
}
