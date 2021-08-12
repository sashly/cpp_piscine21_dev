#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <string>

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm( std::string const &target );
	ShrubberyCreationForm( ShrubberyCreationForm const &src );
	virtual ~ShrubberyCreationForm( void );

	std::string const	&getTarget( void ) const;

	virtual void	action( void ) const;
private:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &rhs );

	std::string	const	target;
};

#endif
