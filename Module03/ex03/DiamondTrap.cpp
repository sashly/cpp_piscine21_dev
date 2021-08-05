#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ) {
	std::cout << "Default DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap( std::string const &name ) : ClapTrap( name
															+ "_clap_name" ),
													  ScavTrap( name ),
													  FragTrap( name ),
													  Name( name ) {
	std::cout << "Name DiamondTrap constructor called\n";
	this->Hitpoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 30;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ) : ClapTrap( src ),
													 Name( src.Name ) {
	std::cout << "Copy DiamondTrap constructor called\n";
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap Destructor called\n";
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &rhs ) {

	std::cout << "DiamondTrap Assignation operator called\n";
	this->ClapTrap::operator=(rhs);
	this->Name = rhs.Name;
	return (*this);
}

void		DiamondTrap::whoAmI( void ) {

	std::cout << "DiamondTrap name is " << this->Name
			  << ", and the ClapTrap name is " << this->ClapTrap::Name << ".\n";
}

void		DiamondTrap::debug( void ) const {

	std::cout << "--------------debug--------------\n"
			  << "DiamondTrap with:\nName: " << this->Name
			  << "\nClaptrap name: " << this->ClapTrap::Name
			  << "\nHitpoints: " << this->Hitpoints << "\nEnergy points: "
			  << this->Energy_points << "\nAttack damage: "
			  << this->Attack_damage << ".\n"
			  << "--------------debug--------------\n";
}
