#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

template<typename A>
void	iter( A *a, int size, void (*f)( A& ) ) {
//	std::cout << "\n" << BLUE << "call normal version" << RESET << "\n";
	for (int i = 0; i < size; i++)
		f( a[i] );
}

template<typename A>
void	iter( A *a, int size, void (*f)( A const & ) ) {
//	std::cout << "\n" << BLUE << "call const version" << RESET << "\n";
	for (int i = 0; i < size; i++)
		f( a[i] );
}

#endif

