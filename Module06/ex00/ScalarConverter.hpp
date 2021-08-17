#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <string>

class ScalarConverter {
public:
	ScalarConverter( std::string const arg );
	~ScalarConverter( void );

private:
	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &src );
	ScalarConverter	&operator=( ScalarConverter const &rhs );

	double	raw_val_;
	bool	is_char;
	bool	is_float;
	bool 	is_pinf;
	bool 	is_ninf;
	bool 	is_nan;
};

#endif
