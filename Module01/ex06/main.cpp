#include "Karen.hpp"
#include <iostream>

int	main(int argc, char **argv) {

	Karen	karen;
	int		lvl_ind;

	if (argc == 2) {
		lvl_ind = karen.lvl_index(argv[1]);
		switch (lvl_ind)
		{
			case 0:  std::cout << "[ DEBUG ]\n";
					 karen.complain("DEBUG");
					 std::cout << "\n";
			case 1:  std::cout << "[ INFO ]\n";
					 karen.complain("INFO");
					 std::cout << "\n";
			case 2:  std::cout << "[ WARNING ]\n";
					 karen.complain("WARNING");
				 	 std::cout << "\n";
			case 3:  std::cout << "[ ERROR ]\n";
					 karen.complain("ERROR");
					 break ;
			default: std::cout << "[ Probably complaining about insignificant"
										  " problems ]\n";
		}
	}
	else
		std::cout << "Usage: ./karenFilter <log_level>;\n";
	return (0);
}
