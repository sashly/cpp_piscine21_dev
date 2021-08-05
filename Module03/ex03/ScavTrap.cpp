#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap() {

	std::cout << "Default ScavTrap constructor called\n";
	this->Hitpoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap( std::string const &name ) : ClapTrap( name ) {

	std::cout << "Name ScavTrap constructor called\n";
	this->Hitpoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap( ScavTrap const &src ) : ClapTrap( src ) {

	std::cout << "Copy ScavTrap constructor called\n";
}

ScavTrap::~ScavTrap( void ) { std::cout << "ScavTrap Destructor called\n"; }

ScavTrap	&ScavTrap::operator=( ScavTrap const &rhs ) {

	std::cout << "ScavTrap Assignation operator called\n";
	this->ClapTrap::operator=(rhs);
	return (*this);
}

void		ScavTrap::attack( std::string const & target ) {

	unsigned int	required_energy = this->Attack_damage;

	if (this->Energy_points >= required_energy) {
		this->Energy_points -= required_energy;
		std::cout << "ScavTrap " << this->Name << " attacks " << target
		<< ", causing " << this->Attack_damage
		<< " points of damage!\n";
	}
	else
		std::cout << "ScavTrap " << this->Name
		<< " don't have enough energy to attack " << target << ".\n";
}

void 		ScavTrap::takeDamage( unsigned int amount ) {

	if (this->Hitpoints >= amount)
		this->Hitpoints -= amount;
	else
		this->Hitpoints = 0;
	std::cout << "ScavTrap " << this->Name << " takes " << amount
	<< " points of damage, left " << this->Hitpoints << ".\n";
}

void 		ScavTrap::beRepaired( unsigned int amount ) {

	this->Hitpoints += amount;
	std::cout << "ScavTrap " << this->Name << " has been repaired with "
	<< amount << " points, " << "current hitpoints are "
	<< this->Hitpoints << ".\n";
}

void		ScavTrap::guardGate( void ) {

	std::cout << "ScavTrap " << this->Name
			  << " have entered in Gate keeper mode.\n";
}
