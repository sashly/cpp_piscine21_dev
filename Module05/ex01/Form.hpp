#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <string>

class Form {
public:
	Form( std::string const &name, int grade_to_sign, int grade_to_exec );
	Form( Form const &src );
	~Form( void );

	std::string const 	&getName( void ) const;
	bool 				getIsSigned( void ) const;
	int 				getGradeSign( void ) const;
	int 				getGradeExec( void ) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char	*what( void ) const throw() {
			return ( "the grade is too high" );
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char	*what( void ) const throw() {
			return ( "the grade is too low" );
		}
	};
	class IsAlreadySigned : public std::exception {
	public:
		virtual const char	*what( void ) const throw() {
			return ( "is already signed" );
		}
	};
	void	beSigned( Bureaucrat const &b ) throw( Form::GradeTooLowException,
							Form::IsAlreadySigned );
private:
	Form( void );
	Form	&operator=( Form const &rhs );

	std::string	const	name;
	bool 				is_signed;
	int const			grade_to_sign;
	int const			grade_to_exec;
};

std::ostream	&operator<<( std::ostream &os, Form const &f );

#endif
