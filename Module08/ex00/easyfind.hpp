#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <algorithm>

template<typename T>
typename T::iterator	easyfind( T &t, int const value ) {
	return ( std::find( t.begin(), t.end(), value ) );
}

template<typename T>
typename T::const_iterator	easyfind( T const &t, int const value ) {
	return ( std::find( t.begin(), t.end(), value ) );
}

#endif
