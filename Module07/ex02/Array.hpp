#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<class T>
class Array {
public:
	Array( void );
	Array( unsigned int const n );
	~Array();
	Array( Array<T> const &src );
	Array<T>	&operator=( Array<T> const &rhs );
	T	&operator[]( int index );
	unsigned int	size( void ) const;
private:
	T				**arr_;
	unsigned int	size_;
};

template<class T>
Array<T>::Array( void ) : arr_( 0 ), size_( 0 ) {}

template<class T>
Array<T>::Array( unsigned const int n ) : arr_( new T*[n] ), size_( n ) {
	for (unsigned int i = 0; i < this->size_; i++)
		this->arr_[i] = new T();
}

template<class T>
Array<T>::~Array( void ) {
	if (this->arr_) {
		for (unsigned int i = 0; i < this->size_; i++)
			delete this->arr_[i];
		delete [] this->arr_;
	}
}

template<class T>
Array<T>::Array( Array<T> const &src ) : arr_( 0 ), size_( 0 ) {
	*this = src;
}

template<class T>
Array<T>	&Array<T>::operator=( Array<T> const &rhs ) {
	if (this != &rhs) {
		if (this->arr_) {
			for (unsigned int i = 0; i < this->size_; i++)
				delete this->arr_[i];
			delete [] this->arr_;
		}
		this->arr_ = new T*[rhs.size()];
		for (unsigned int i = 0; i < rhs.size(); ++i)
			this->arr_[i] = new T( *(rhs.arr_[i]) );
	}
	return ( *this );
}

template<class T>
T	&Array<T>::operator[]( int index ) {
	if (!(index >= 0 && index < static_cast<int>( this->size_ )))
		throw ( std::exception() );
	return ( *(this->arr_[index]) );
}

template<class T>
unsigned int	Array<T>::size( void ) const {
	return ( this->size_ );
}

#endif

