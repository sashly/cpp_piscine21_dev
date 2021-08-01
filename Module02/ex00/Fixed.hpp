#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:

	Fixed();
	~Fixed();
	Fixed(Fixed const &cp);

	Fixed const &operator=(Fixed const &rhs);

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

private:
	static const int	fract_bits = 8;

	int	value_;

};

#endif
