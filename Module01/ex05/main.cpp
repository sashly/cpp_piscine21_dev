#include "Karen.hpp"
#include <iostream>

int	main( void ) {

	Karen	karen;

	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");

	karen.complain("INFO");
	karen.complain("INFO");
	karen.complain("INFO");
	karen.complain("INFO");
	karen.complain("INFO");

	karen.complain("ERROR");

	karen.complain("ERRORR");
	karen.complain("fsdfsdf");
	karen.complain("");

	return (0);
}
