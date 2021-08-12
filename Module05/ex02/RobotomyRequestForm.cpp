#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
		: Form( "RobotomyRequestForm", 72, 45 ), target( "" ) {}

RobotomyRequestForm::RobotomyRequestForm( std::string const &t )
		: Form( "RobotomyRequestForm", 72, 45 ), target( t ) {}

RobotomyRequestForm::RobotomyRequestForm(
				RobotomyRequestForm const &src ) : Form( src ),
												   target( src.target ) {}

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

	std::cout << "bzzbzbbzbzbzbzbzzzz...\n";
	std::cout << this->getTarget()
			  << " has been robotomized successfully 50% of the time.\n";
}
