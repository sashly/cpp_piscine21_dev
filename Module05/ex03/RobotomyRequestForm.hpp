#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <string>

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm( std::string const &target );
	RobotomyRequestForm( RobotomyRequestForm const &src );
	virtual ~RobotomyRequestForm( void );

	std::string const	&getTarget( void ) const;

	virtual void	action( void ) const;
private:
	RobotomyRequestForm( void );
	RobotomyRequestForm	&operator=( RobotomyRequestForm const &rhs );

	std::string	const	target;
};

#endif
