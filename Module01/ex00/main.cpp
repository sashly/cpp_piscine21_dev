#include "Zombie.hpp"

int	main( void ) {

	Zombie *zombie1;
	Zombie *zombie2;
	Zombie *zombie3;

	zombie1 = newZombie("heap_zombie1");
	if (zombie1)
		zombie1->announce();
	zombie2 = newZombie("heap_zombie2");
	if (zombie2)
		zombie2->announce();
	zombie3 = newZombie("heap_zombie3");
	if (zombie3)
		zombie3->announce();

	randomChump("stack_zombie1");
	randomChump("stack_zombie2");
	randomChump("stack_zombie3");

	delete zombie1;
	delete zombie2;
	delete zombie3;
	return (0);
}
