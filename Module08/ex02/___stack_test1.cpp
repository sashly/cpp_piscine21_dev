#include <iostream>
#include <string>
#include <vector>
#include <stack>

class MStack : public std::stack<int, std::vector<int>> {
public:
	void push( const int &value ) {
		this->c.push_back( value );
	}
//	using std::vector<int>::iterator;
	typedef std::vector<int>::iterator iterator;
	iterator	begin( void ) {
		return ( this->c.begin() );
	}
	iterator	end( void ) {
		return ( this->c.end() );
	}
private:
};

int main( void ) {

	MStack	ms;

//	(void)ms;

	ms.push( 5 );
	ms.push( 3 );
	ms.push( 1 );
//	std::cout << ms.top() << "\n";

	MStack::iterator	start = ms.begin();
	MStack::iterator	end = ms.end();
//	std::cout << *it << "\n";
	//	(void)it;

	while (start != end) {
		std::cout << *start << "\n";
		start++;
	}

	return ( 0 );
}
