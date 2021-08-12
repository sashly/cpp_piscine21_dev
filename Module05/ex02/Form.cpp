#include "Form.hpp"
#include <iomanip>

Form::Form( void ) : name( "" ), is_signed( false ),
					 grade_to_sign( 1 ), grade_to_exec( 1 ) {}

Form::Form( std::string const &name,
			int g_to_sign, int g_to_exec ) : name( name ), is_signed( false ),
											 grade_to_sign( g_to_sign ),
											 grade_to_exec( g_to_exec ) {
	if (this->grade_to_sign > 150)
		throw ( Form::GradeTooLowException() );
	if (this->grade_to_sign < 1)
		throw ( Form::GradeTooHighException() );
	if (this->grade_to_exec > 150)
		throw ( Form::GradeTooLowException() );
	if (this->grade_to_exec < 1)
		throw ( Form::GradeTooHighException() );
}

Form::Form( Form const &src ) : name( src.name ), is_signed( src.is_signed ),
								grade_to_sign( src.grade_to_sign ),
								grade_to_exec( src.grade_to_exec ) {}

Form::~Form( void ) {}

Form	&Form::operator=( Form const &rhs ) {

	(void)rhs;
	return (*this);
}


std::string const 	&Form::getName( void ) const {

	return ( this->name );
}

bool	Form::getIsSigned( void ) const {

	return ( this->is_signed );
}

int	Form::getGradeSign( void ) const {

	return ( this->grade_to_sign );
}

int	Form::getGradeExec( void ) const {

	return ( this->grade_to_exec );
}

void	Form::beSigned( Bureaucrat const &b ) throw( Form::GradeTooLowException,
			Form::IsAlreadySigned ) {

	if (this->is_signed == true)
		throw ( Form::IsAlreadySigned() );
	if (this->grade_to_sign < b.getGrade())
		throw ( Form::GradeTooLowException() );
	this->is_signed = true;
}

void	Form::execute( Bureaucrat const &executor ) const
					throw( Form::GradeTooLowException, Form::IsNotSigned ) {

	if (this->is_signed == false)
		throw ( Form::IsNotSigned() );
	if (executor.getGrade() > this->grade_to_exec)
		throw ( Form::GradeTooLowException() );
	this->action();
}

std::ostream	&operator<<( std::ostream &os, Form const &f ) {

	os << "Form name: " << f.getName() << ", is_signed: " << std::boolalpha
	   << f.getIsSigned() << ", grade_to_sign: " << f.getGradeSign()
	   << ", grade_to_exec: " << f.getGradeExec() << ".";
	return ( os );
}
