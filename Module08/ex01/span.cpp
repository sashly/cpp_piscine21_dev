#include "span.hpp"
#include <algorithm>

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
}

int		Span::shortestSpan( void ) const throw( std::logic_error ) {
	if (this->count_ < 2)
		throw ( std::logic_error( "must be at least 2 numbers to find span" ) );
	std::vector<int>	sort( this->cont_ );
	std::sort( sort.begin(), sort.end() );
	return ( sort[1] - sort[0] );
}

int		Span::shortestSpan( bool ) const throw( std::logic_error ) {
	if (this->count_ < 2)
		throw ( std::logic_error( "must be at least 2 numbers to find span" ) );
	std::vector<int>	tmp( this->cont_ );
	int 				itmp;
	std::vector<int>::iterator min = std::min_element( tmp.begin(), tmp.end() );
	itmp = *min;
	tmp.erase( min );
	min = std::min_element( tmp.begin(), tmp.end() );
	return ( *min - itmp );
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
