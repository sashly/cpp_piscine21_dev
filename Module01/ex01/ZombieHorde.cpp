#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	Zombie *zmb_horde = new Zombie[N];

	for (int i = 0; i < N; ++i)
		zmb_horde[i].init_default(name);
	return (zmb_horde);
}
