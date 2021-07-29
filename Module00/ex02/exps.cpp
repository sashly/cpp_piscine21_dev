#include <iostream>
#include <ctime>

void	put_nbr(int nbr) {

	if (nbr > 9)
		std::cout << nbr;
	else
		std::cout << '0' << nbr;
}

int	main( void ) {

	std::time_t	now = std::time(0);
	std::tm		*nnow = std::gmtime(&now);
	std::cout << std::ctime(&now);

	std::cout << "tm->tm_year: " << nnow->tm_year + 1900 << "\n"
			  << "tm->tm_mon:  " << nnow->tm_mon + 1 << "\n"
			  << "tm->tm_mday: " << nnow->tm_mday << "\n"
			  << "tm->tm_hour: " << nnow->tm_hour << "\n"
			  << "tm->tm_min:  " << nnow->tm_min << "\n"
			  << "tm->tm_sec:  " << nnow->tm_sec << "\n";

//	[19920104_091532]

	std::cout << "[" << nnow->tm_year + 1900;
	put_nbr(nnow->tm_mon + 1);
	put_nbr(nnow->tm_mday);
	std::cout << '_';
	put_nbr(nnow->tm_hour);
	put_nbr(nnow->tm_min);
	put_nbr(nnow->tm_sec);
	std::cout << "]";

	std::cout << std::endl;

	return (0);
}
