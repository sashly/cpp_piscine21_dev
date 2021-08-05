#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main( void ) {

	FragTrap	frag("FRAAAG");

	std::cout << "\n";
	frag.attack( "annoying mosquito" );
	frag.takeDamage( 50 );
	frag.beRepaired( 20 );
	frag.highFivesGuys();
	std::cout << "\n";

	return (0);
}
