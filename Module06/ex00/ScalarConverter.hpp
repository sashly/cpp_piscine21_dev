#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <string>

class ScalarConverter {
public:
	ScalarConverter( std::string const arg );
	~ScalarConverter( void );

	void	convert( void ) const;
	void	debug( void ) const;

private:
	typedef enum { INV, CHAR, INT, FLOAT, DOUBLE } e_type;

	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &src );
	ScalarConverter	&operator=( ScalarConverter const &rhs );

	static bool	is_spec_double( double val );
	static bool is_valid_float( double val );
	void 		char_input( char c );
	void		is_input_valid( void );

	void	convert_char( void ) const;
	void	convert_int( void ) const;
	void	convert_float( void ) const;
	void	convert_double( void ) const;

	double	raw_val_;
	e_type	type_;
	bool 	is_spec_float_;
};

#endif
