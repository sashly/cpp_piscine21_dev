#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ) {
	std::cout << "Default DiamondTrap constructor called\n"; }

DiamondTrap::DiamondTrap( std::string const &name ) :  ScavTrap( name ), FragTrap( name ) {

	std::cout << "Name DiamondTrap constructor called\n";
	ClapTrap::Name = name + "_clap_name";
	this->Name = name;
	this->Hitpoints = FragTrap::Hitpoints;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ) { (void)src; }

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called\n"; }

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &rhs ) {

	(void)rhs;
	return (*this);
}

void		DiamondTrap::whoAmI( void ) {

	std::cout << "DiamondTrap name is " << this->Name
			  << ", and the ClapTrap name is " << ClapTrap::Name << ".\n";
}
