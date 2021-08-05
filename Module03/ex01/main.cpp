#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main( void ) {

	ScavTrap	scav( "SCAAAV" );
//	std::cout << "\n";
//	ScavTrap	scav1( scav );
//	std::cout << "\n";
//	ScavTrap	scav_def;
//	std::cout << "\n";
//	scav_def = scav;
//	scav1.attack( "fly" );
//	scav_def.attack( "flyyyy" );

	std::cout << "\n";
	scav.attack( "very big fly" );
	scav.takeDamage( 35 );
	scav.takeDamage( 15 );
	scav.beRepaired( 50 );
	scav.guardGate();
	std::cout << "\n";

//	ClapTrap	clap( "CLAAAP" );
//	clap.attack( "gnat" );
//	clap.takeDamage( 100 );
//	clap.beRepaired( 50 );
//	std::cout << "\n";

	return (0);
}
