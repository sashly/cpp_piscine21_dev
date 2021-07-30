#include <iostream>
#include <iomanip>
#include <string>

int	main( void ) {

	std::string	string("HI THIS IS BRAIN");

	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "The address in memory of the string (\""
		      << string << "\") is: " << &string << "\n"
		      << "The address using stringPTR:" << std::setw(47) << stringPTR
		      << "\nThe address using stringREF:" << std::setw(47)
		      << &stringREF << "\n";

	std::cout << "\nDisplaying the string (\"" << string << "\"):\n"
			  << "          o using the pointer:   " << *stringPTR << "\n"
			  << "          o using the reference: " << stringREF << std::endl;

	return (0);
}
