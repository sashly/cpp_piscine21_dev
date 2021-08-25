#include "Array.hpp"
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <time.h>

#define MAX_VAL 750

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

template<typename T>
void	print_arr( Array<T> const &arr, unsigned int const size,
				   							char const *arr_name ) {
	std::cout << arr_name << ":";
	for (unsigned int i = 0; i < size; i++)
		std::cout << " " << arr[i];
	std::cout << "\n";
}

int	main( void ) {
	{
		std::cout << GREEN << "\t--> SUBJECT TEST: <--" << RESET << "\n";
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
//		SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return ( 1 );
			}
		}
		try {
			numbers[-2] = 0;
		}
		catch(const std::exception& e) {
			std::cout << "access -2 element: ";
			std::cerr << e.what() << '\n';
		}
		try {
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e) {
			std::cout << "access MAX_VAL element: ";
			std::cerr << e.what() << '\n';
		}
		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		delete [] mirror;
	}
//	try {
//		std::cout << GREEN << "\n\t--> ACCESS TESTS: <--" << RESET << "\n";
//		Array<int> numbers( MAX_VAL );
//		Array<int> numbers_big( 2147483777u );
//		//3147483647u
//		try {
//			numbers[-1] = 7;
//		}
//		catch(const std::exception& e) {
//			std::cerr << "access element: ";
//			std::cerr << e.what() << '\n';
//		}
//		try {
//			numbers[MAX_VAL] = 7;
//		}
//		catch(const std::exception& e) {
//			std::cerr << "access element: ";
//			std::cerr << e.what() << '\n';
//		}
//		try {
//			numbers_big[2147483775u] = 7;
//			std::cout << "element with index 2147483775u is: "
//					  << numbers_big[2147483775u] << "\n";
//		}
//		catch(const std::exception& e) {
//			std::cerr << "access element: ";
//			std::cerr << e.what() << '\n';
//		}
//		try {
//			numbers_big[-2147483647] = 7;
//		}
//		catch(const std::exception& e) {
//			std::cerr << "access element: ";
//			std::cerr << e.what() << '\n';
//		}
//	}
//	catch ( std::exception const &e ) {
//		std::cerr << e.what() << "\n";
//	}
	{
		std::cout << GREEN << "\n\t--> EMPTY ARRAY TESTS: <--" << RESET << "\n";
		Array<int> iarr;
		std::cout << "size of iarr: "<< iarr.size() << "\n";
		try {
			std::cout << iarr[0] << "\n";
		}
		catch (std::exception &e) {
			std::cout << "accessing an empty array: "<< e.what() << "\n";
		}
	}
	{
		std::cout << GREEN << "\n\t--> SOME TESTS: <--" << RESET << "\n";
		unsigned int const	iarr_size = 27;
		Array<int>	iarr( iarr_size );
		print_arr<int>( iarr, iarr_size, "iarr" );
		for (unsigned int i = 0; i < iarr_size; i++)
			iarr[i] = rand() % 100;
		print_arr<int>( iarr, iarr_size, "iarr" );

		std::cout << GREEN << "\n\t--> COPY TESTS: <--" << RESET << "\n";
		Array<int>	iarr2( iarr );
		Array<int>	iarr3( 100 );
		iarr3 = iarr2;
		print_arr<int>( iarr2, iarr2.size(), "iarr2" );
		print_arr<int>( iarr3, iarr3.size(), "iarr3" );

		std::cout << GREEN << "\n\t--> ACCESS CONST TESTS: <--"
				  << RESET << "\n";
		Array<int> const	iarrc( iarr2 );
		for (unsigned int i = 0; i < iarr2.size(); i++)
			iarr2[i] = i + 1;
		print_arr<int>( iarr2, iarr2.size(), "iarr2" );
		print_arr<int>( iarrc, iarrc.size(), "iarr3" );
//		iarrc[0] = 7;
	}

	return ( 0 );
}
