#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:

	Fixed();
	Fixed(int const i);
	Fixed(float const f);

	~Fixed();
	Fixed(Fixed const &cp);

	static Fixed	&max(Fixed &a, Fixed &b);
	static Fixed const	&max(Fixed const &a, Fixed const &b);

	Fixed const &operator=(Fixed const &rhs);

	bool		operator>(Fixed const &rhs) const;
	bool		operator<(Fixed const &rhs) const;
	bool		operator>=(Fixed const &rhs) const;
	bool		operator<=(Fixed const &rhs) const;
	bool		operator==(Fixed const &rhs) const;
	bool		operator!=(Fixed const &rhs) const;

	Fixed		operator+(Fixed const &rhs) const;
	Fixed		operator-(Fixed const &rhs) const;
	Fixed		operator*(Fixed const &rhs) const;
	Fixed		operator/(Fixed const &rhs) const;

	Fixed const	&operator++();
	Fixed const	operator++(int);
	Fixed const	&operator--();
	Fixed const	operator--(int);

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

	float		toFloat( void ) const;
	int 		toInt( void ) const;

private:

	static const int	fract_bits = 8;
	int					value_;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &rhs);

#endif
