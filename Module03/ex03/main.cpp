#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main( void ) {

	DiamondTrap	test( "DIAMOND" );
//	DiamondTrap	test1( test );
//	DiamondTrap	test2;

//	std::cout << "\n";
////	std::cout << sizeof(std::string) << "\n";
//	std::cout << "sizeof( ClapTrap ): " << sizeof(ClapTrap)
//			  << "\nsizeof( ScavTrap ): " << sizeof(ScavTrap)
//			  << "\nsizeof( FragTrap ): " << sizeof(FragTrap)
//			  << "\nsizeof( DiamondTrap ): " << sizeof(DiamondTrap) << "\n";

	std::cout << "\n";
	test.debug();
	std::cout << "\n";
	test.whoAmI();
	test.attack( "big gnat" );
	test.guardGate();
	test.highFivesGuys();
	std::cout << "\n";

	return (0);
}
