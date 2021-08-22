#ifndef ITER_HPP
# define ITER_HPP

template<typename A>
void	iter( A *a, int size, void (*f)( A ) ) {
	for (int i = 0; i < size; i++)
		f( a[i] );
}

#endif
