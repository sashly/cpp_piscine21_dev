#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

# include "Form.hpp"
# include <string>

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm( std::string const &target );
	PresidentialPardonForm( PresidentialPardonForm const &src );
	virtual ~PresidentialPardonForm( void );

	std::string const	&getTarget( void ) const;

	virtual void	action( void ) const;
private:
	PresidentialPardonForm( void );
	PresidentialPardonForm	&operator=( PresidentialPardonForm const &rhs );

	std::string	const	target;
};

#endif
