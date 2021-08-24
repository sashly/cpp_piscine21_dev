#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span {
public:
	Span( void );
	Span( unsigned int const N );
	Span( Span const &src );
	~Span( void );
	Span	&operator=( Span const &rhs );

	unsigned int	getN( void ) const;
	unsigned int	getCount( void ) const;

	void 			addNumber( int const val ) throw( std::logic_error );

	template<class It>
	void	addRange( It begin, It end ) throw( std::logic_error );

	int		shortestSpan( void ) const throw( std::logic_error );
	int 	shortestSpan( bool ) const throw( std::logic_error );
	int		longestSpan( void ) const throw( std::logic_error );
private:
	unsigned int 		N_;
	unsigned int		count_;
	std::vector<int>	cont_;
};

template<class It>
void	Span::addRange( It begin, It end ) throw( std::logic_error ) {
	if (std::distance( begin, end ) > (this->N_ - this->count_))
		throw ( std::logic_error( "cannot add elements range" ) );
	this->count_ = std::distance( begin, end );
	this->cont_.insert( this->cont_.end(), begin, end );
}

#endif
