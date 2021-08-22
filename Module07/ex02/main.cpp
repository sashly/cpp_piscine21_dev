#include "Array.hpp"
#include <iostream>
#include <exception>

template<typename T>
void	print_arr( Array<T> &arr, int size, char const *arr_name ) {
	std::cout << arr_name << ":";
	for (int i = 0; i < size; i++)
		std::cout << " " << arr[i];
	std::cout << "\n";
}

int	main( void ) {

	{
		Array<int> iarr;
		std::cout << iarr.size() << "\n";
		try
		{
			std::cout << iarr[0] << "\n";
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
	}
	{
		int const	iarr_size = 11;
		Array<int>	iarr( iarr_size );
		print_arr<int>( iarr, iarr_size, "iarr" );
		for (int i = 0; i < iarr_size; i++)
			iarr[i] = i + 1;
		print_arr<int>( iarr, iarr_size, "iarr" );

		Array<int>	iarr2( iarr );
		(void)iarr;
	}


	return ( 0 );
}
