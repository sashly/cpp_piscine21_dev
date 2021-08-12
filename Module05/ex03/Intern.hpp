#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include <string>

class Intern {
public:
	Intern( void );
	Intern( Intern const &src );
	~Intern( void );
	Intern	&operator=( Intern const &rhs );

	Form	*makeForm( std::string const &form_name,
					   std::string const &target) const;
private:
	int 						formIndex( std::string const &find ) const;

	static int const			forms_size = 3;
	static std::string const 	forms[forms_size];
};

#endif
