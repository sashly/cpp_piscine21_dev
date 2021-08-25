#include "span.hpp"
#include <algorithm>
#include <limits>

Span::Span( void ) : N_( 0 ), count_( 0 ) {}

Span::Span( unsigned int const N ) : N_( N ), count_( 0 ) {}

Span::Span( Span const &src ) : N_( src.N_ ), count_( src.count_ ) {
	for (size_t i = 0; i < src.cont_.size(); i++)
		this->cont_.push_back( src.cont_[i] );
}

Span::~Span( void ) {}

Span	&Span::operator=( Span const &rhs ) {

	if (this != &rhs) {
		if (this->count_)
			this->cont_.clear();
		this->N_ = rhs.N_;
		this->count_ = rhs.count_;
		for (size_t i = 0; i < rhs.cont_.size(); i++)
			this->cont_.push_back( rhs.cont_[i] );
	}
	return (*this);
}

unsigned int	Span::getN( void ) const {
	return ( this->N_ );
}

unsigned int	Span::getCount( void ) const {
	return ( this->count_ );
}

void	Span::addNumber( int const val ) throw( std::logic_error ) {
	if (this->count_ == this->N_)
		throw ( std::logic_error( "cannot add element - already full" ) );
	this->count_++;
	this->cont_.push_back( val );
	this->map_.insert( val );
}

int		Span::shortestSpan( void ) const throw( std::logic_error ) {
	if (this->count_ < 2)
		throw ( std::logic_error( "must be at least 2 numbers to find span" ) );
	int		min = std::numeric_limits<int>::max();
	std::multiset<int>::iterator it_next = this->map_.begin();
	it_next++;
	for (std::multiset<int>::iterator it = this->map_.begin(); it_next != this->map_.end(); it++) {
		if (*it_next - *it < min)
			min = *it_next - *it;
		if (min == 0)
			return ( 0 );
		it_next++;
	}
	return ( min );
}

int		Span::longestSpan( void ) const throw( std::logic_error ) {
	if (this->count_ < 2)
		throw ( std::logic_error( "must be at least 2 numbers to find span" ) );
	std::vector<int>::const_iterator
			min = std::min_element( this->cont_.begin(), this->cont_.end() );
	std::vector<int>::const_iterator
			max = std::max_element( this->cont_.begin(), this->cont_.end() );
	return ( *max - *min );
}
