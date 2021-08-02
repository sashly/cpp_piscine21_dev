#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:

	Fixed( void );
	Fixed( Fixed const &src );
	~Fixed( void );

	Fixed		&operator=(Fixed const &rhs);

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

private:
	static const int	fract_bits = 8;
	int					raw_value_;
};

#endif
