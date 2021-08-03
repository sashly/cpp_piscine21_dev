#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) {
	std::cout << "Default ScavTrap constructor called\n"; }

ScavTrap::ScavTrap( std::string const &name ) : ClapTrap( name ) {

	std::cout << "Name ScavTrap constructor called\n";
	this->Hitpoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap( ScavTrap const &src ) {

	std::cout << "Copy ScavTrap constructor called\n";
	*this = src;
}

ScavTrap::~ScavTrap( void ) { std::cout << "ScavTrap Destructor called\n"; }

ScavTrap	&ScavTrap::operator=( ScavTrap const &rhs ) {

	(void)rhs;
	std::cout << "ScavTrap Assignation operator called\n";
	return (*this);
}

void		ScavTrap::guardGate( void ) {

	std::cout << "ScavTrap " << this->Name
			  << "have entered in Gate keeper mode.\n";
}

