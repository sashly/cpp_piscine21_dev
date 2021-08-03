#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main( void ) {

	ScavTrap	scav("scaaav");

	scav.attack( "very big fly" );
	scav.takeDamage( 5 );
	scav.takeDamage( 35 );

	scav.beRepaired( 100 );

	return (0);
}
