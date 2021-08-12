#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form( "PresidentialPardonForm", 25, 5 ), target( "" ) {}

PresidentialPardonForm::PresidentialPardonForm( std::string const &t )
	: Form( "PresidentialPardonForm", 25, 5 ), target( t ) {}

PresidentialPardonForm::PresidentialPardonForm(
		PresidentialPardonForm const &src ) : Form( src ),
											  target( src.getTarget() ) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm
	&PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs ) {

	(void)rhs;
	return (*this);
}

std::string const	&PresidentialPardonForm::getTarget( void ) const {

	return ( this->target );
}

void	PresidentialPardonForm::action( void ) const {

	std::cout << this->getTarget()
			  << " has been pardoned by Zafod Beeblebrox.\n";
}
