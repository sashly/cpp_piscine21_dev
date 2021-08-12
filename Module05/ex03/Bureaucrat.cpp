#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name( "John" ), grade( 150 ) {}

Bureaucrat::Bureaucrat( std::string const &n,
						int const grade ) : name( n ) {
	if (grade < 1)
		throw ( Bureaucrat::GradeTooHighException() );
	else if (grade > 150)
		throw ( Bureaucrat::GradeTooLowException() );
	this->grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : name( src.getName() ),
												  grade( src.getGrade() ) {}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &rhs ) {

	(void)rhs;
	return (*this);
}

std::string const	&Bureaucrat::getName( void ) const {

	return ( this->name );
}

int	Bureaucrat::getGrade( void ) const {

	return (this->grade );
}

void	Bureaucrat::incGrade( void ) throw( Bureaucrat::GradeTooHighException )
{

	if ( this->grade == 1)
		throw ( Bureaucrat::GradeTooHighException() );
	this->grade--;
}

void	Bureaucrat::decGrade( void ) throw( Bureaucrat::GradeTooLowException )
{
	if ( this->grade == 150)
		throw ( Bureaucrat::GradeTooLowException() );
	this->grade++;
}

void	Bureaucrat::signForm( Form &f ) const throw() {

	try {
		f.beSigned( *this );
		std::cout << this->getName() << " signs " << f.getName() << "\n";
	}
	catch ( std::exception &e ) {
		std::cout << this->getName() << " cannot sign "
				  << f.getName() << " because " << e.what() << "\n";
	}
}

void 	Bureaucrat::executeForm( Form const & f ) const throw() {

	try {
		f.execute( *this );
		std::cout << this->getName() << " executes " << f.getName() << "\n";
	}
	catch ( std::exception &e ) {
		std::cout << this->getName() << " cannot execute "
				  << f.getName() << " because " << e.what() << "\n";
	}
}

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b ) {

	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return ( os );
}
