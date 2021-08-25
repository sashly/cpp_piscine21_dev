#include "mutantstack.hpp"
#include <iostream>

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"
#define RED     	"\033[31m"
#define GREEN  		"\033[32m"
#define YELLOW  	"\033[33m"
#define BLUE    	"\033[34m"
#define MAGENTA 	"\033[35m"
#define CYAN    	"\033[36m"
#define WHITE   	"\033[37m"

int	main( void ) {

	{
		std::cout << GREEN <<"\t--> SUBJECT TEST: <--" << RESET << "\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		while (!s.empty()) {
			std::cout << s.top() << "\n";
			s.pop();
		}
	}
	{
		std::cout << GREEN <<"\t--> SOME TESTS: <--" << RESET << "\n";
		MutantStack<int> mstack;
		mstack.push( 3 );
		mstack.push( 0 );
		mstack.push( -11 );
		mstack.push( 313 );
		mstack.push( 12 );
		std::cout << "\tIterator:\n";
		for (MutantStack<int>::iterator it = mstack.begin();
												it != mstack.end(); it++) {
			std::cout << *it << "\n";
		}
		std::cout << "\tConst iterator:\n";
		MutantStack<int> const mstack_copy( mstack );
		for (MutantStack<int>::const_iterator it = mstack_copy.begin();
										it != mstack_copy.end(); it++) {
			std::cout << *it << "\n";
		}
	}

	return ( 0 );
}
