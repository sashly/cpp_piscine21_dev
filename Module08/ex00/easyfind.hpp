#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

template<typename T>
typename T::iterator	easyfind( T &t, int value ) {
	typename T::iterator start = t.begin();
	typename T::iterator end = t.end();
	while (start != end) {
		if (*start == value)
			return (start);
		start++;
	}
	return ( end );
}

#endif
