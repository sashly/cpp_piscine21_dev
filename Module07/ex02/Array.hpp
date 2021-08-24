#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template<class T>
class Array {
public:
	Array( void );
	Array( unsigned int const n );
	~Array( void );
	Array( Array<T> const &src );
	Array<T>	&operator=( Array<T> const &rhs );
	T	&operator[]( unsigned int const index ) throw( std::exception );
	T	&operator[]( int const index ) throw( std::exception );
	T const	&operator[]( unsigned int const index ) const
														throw( std::exception );
	T const	&operator[]( int const index ) const throw( std::exception );
	unsigned int	size( void ) const;
private:
	T				*arr_;
	unsigned int	size_;
};

template<class T>
Array<T>::Array( void ) : arr_( 0 ), size_( 0 ) {}

template<class T>
Array<T>::Array( unsigned const int n ) : arr_( new T[n]() ), size_( n ) {}

template<class T>
Array<T>::~Array( void ) {
	if (this->arr_)
		delete [] this->arr_;
}

template<class T>
Array<T>::Array( Array<T> const &src ) : arr_( 0 ), size_( 0 ) {
	*this = src;
}

template<class T>
Array<T>	&Array<T>::operator=( Array<T> const &rhs ) {
	if (this != &rhs) {
		if (this->arr_)
			delete [] this->arr_;
		this->size_ = rhs.size();
		this->arr_ = new T[this->size_]();
		for (unsigned int i = 0; i < this->size_; i++)
			this->arr_[i] = rhs.arr_[i];
	}
	return ( *this );
}

template<class T>
T	&Array<T>::operator[]( unsigned int const index ) throw( std::exception ) {
//	std::cout << "operator[] unsigned version, " << "index: " << index << "\n";
	if (index >= this->size_)
		throw ( std::exception() );
	return ( this->arr_[index] );
}

template<class T>
		T	&Array<T>::operator[]( int const index ) throw( std::exception ){
//	std::cout << "operator[] int version, " << "index: " << index << "\n";
	if (index < 0 || static_cast<unsigned int>( index ) >= this->size_ )
		throw ( std::exception() );
	return ( this->arr_[index] );
}

template<class T>
T	const &Array<T>::operator[]( int const index ) const
        											throw( std::exception ) {
	if (index < 0 || static_cast<unsigned int>( index ) >= this->size_ )
		throw ( std::exception() );
	return ( this->arr_[index] );
}

template<class T>
T const	&Array<T>::operator[]( unsigned int const index ) const
													throw( std::exception ) {
	if (index >= this->size_)
		throw ( std::exception() );
	return ( this->arr_[index] );
}

template<class T>
unsigned int	Array<T>::size( void ) const {
	return ( this->size_ );
}

#endif

