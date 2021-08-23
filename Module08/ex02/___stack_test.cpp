#include <iostream>
#include <stack>

int	main( void ) {
	std::stack<int>	st;

	for (int i = 0; i < 21; i++)
		st.push( i + 1 );
	std::stack<int>::iterator	it = st.top();

	return ( 0 );
}
