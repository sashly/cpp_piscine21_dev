#include "ClapTrap.hpp"
#include <iostream>

int	main( void ) {

	ClapTrap	clap( "claaap" );
	ClapTrap	clap_cp( clap );
	ClapTrap	clap_cp1;

	clap_cp1 = clap;

	std::cout << "\n";
	clap.attack( "big fly" );
	clap.takeDamage( 5 );
	clap.takeDamage( 25 );
	clap.beRepaired( 15 );
	std::cout << "\n";

	return (0);
}
