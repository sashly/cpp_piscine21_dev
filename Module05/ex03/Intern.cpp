#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string const	Intern::forms[Intern::forms_size] = { "shrubbery creation",
														   "robotomy request",
														   "presidential pardon"
														};
Intern::Intern( void ) {}

Intern::Intern( Intern const &src ) {

	(void)src;
}

Intern::~Intern( void ) {}

Intern	&Intern::operator=( Intern const &rhs ) {

	(void)rhs;
	return (*this);
}

int	Intern::formIndex( std::string const &find ) const {

	for (int i = 0; i < this->forms_size; i++)
		if (this->forms[i] == find)
			return ( i );
	return ( -1 );
}

Form	*Intern::makeForm( std::string const &form_name,
				   std::string const &target) const {

	int		index = this->formIndex( form_name );

	switch ( index )
	{
		case 0: std::cout << "Intern creates " << form_name << "\n";
				return ( new ShrubberyCreationForm( target ) );
		case 1: std::cout << "Intern creates " << form_name << "\n";
				return ( new RobotomyRequestForm( target ) );
		case 2: std::cout << "Intern creates " << form_name << "\n";
				return ( new PresidentialPardonForm( target ) );
		default: std::cout << "Intern cannot create " << form_name << "\n";
	}
	return ( 0 );
}
