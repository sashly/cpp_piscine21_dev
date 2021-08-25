#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<class T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator	iterator;
	typedef typename std::stack<T>::container_type::const_iterator
																const_iterator;
	MutantStack( void );
	MutantStack( MutantStack const &src );
	MutantStack	&operator=( MutantStack const &rhs );
	~MutantStack( void );
	iterator	begin( void );
	iterator	end( void );
	const_iterator	begin( void ) const;
	const_iterator	end( void ) const;
};

template<typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack( MutantStack<T> const &src )
									: std::stack<T>( src ) {}

template<typename T>
MutantStack<T>::~MutantStack( void ) {}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=( MutantStack<T> const &rhs ) {
	if (this != &rhs) {
		this->std::stack<T>.operator=( rhs );
	}
	return ( *this );
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return ( this->c.begin() );
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return ( this->c.end() );
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin( void ) const {
	return ( this->c.begin() );
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end( void ) const {
	return ( this->c.end() );
}

#endif
