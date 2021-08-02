#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:

	Fixed( void );
	Fixed( int const i );
	Fixed( float const f );
	Fixed( Fixed const &src );
	~Fixed( void );

	Fixed		&operator=( Fixed const &rhs );

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

	float		toFloat( void ) const;
	int 		toInt( void ) const;

private:
	static const int	fract_bits = 8;
	int					raw_value_;
};

std::ostream	&operator<<( std::ostream &os, Fixed const &rhs );

#endif
