#ifndef DATA_HPP
# define DATA_HPP

class Data {
public:
	Data( void );
	Data( int const v );
	Data( Data const &src );
	~Data( void );
	Data	&operator=( Data const &rhs );

	int		getVal( void ) const;
	void	hello( void ) const;
private:
	int	val_;
};

#endif
