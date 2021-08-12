#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat;
class Form;
# include "Form.hpp"
# include <exception>
# include <iostream>
# include <string>

class Bureaucrat {
public:
	Bureaucrat( std::string const &name, int grade );
	Bureaucrat( Bureaucrat const &src );
	~Bureaucrat( void );

	std::string const	&getName( void ) const;
	int					getGrade( void ) const;

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

	void	incGrade( void ) throw( Bureaucrat::GradeTooHighException );
	void	decGrade( void ) throw( Bureaucrat::GradeTooLowException );

	void	signForm( Form &f ) const throw();
	void 	executeForm( Form const & form ) const throw();
private:
	Bureaucrat( void );
	Bureaucrat	&operator=( Bureaucrat const &rhs );

	std::string const	name;
	int 				grade;
};

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b );

#endif
