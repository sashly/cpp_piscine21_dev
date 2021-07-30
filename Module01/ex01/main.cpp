#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

int	main(int argc, char **argv) {

	Zombie		*zmb_horde;
	std::string	zmb_name;
	int 		n_zmb;
	int 		tmp;

	zmb_name = "zzzombie";
	n_zmb = 11;
	if (argc > 1) {
		tmp = std::atoi(argv[1]);
		if (tmp > 0  && tmp <= 1000)
			n_zmb = tmp;
	}
	zmb_horde = zombieHorde(n_zmb, zmb_name);
	if (!zmb_horde)
		return (1);

	for (int i = 0; i < n_zmb; ++i)
		zmb_horde[i].announce();

	delete [] zmb_horde;
	return (0);
}
