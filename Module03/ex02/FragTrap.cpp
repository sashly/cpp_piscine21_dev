#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap() {

	std::cout << "Default FragTrap constructor called\n";
	this->Hitpoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap( std::string const &name ) : ClapTrap( name ) {

	std::cout << "Name FragTrap constructor called\n";
	this->Hitpoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap( FragTrap const &src ) : ClapTrap( src ) {

	std::cout << "Copy FragTrap constructor called\n";
}

FragTrap::~FragTrap( void ) { std::cout << "FragTrap Destructor called\n"; }

FragTrap	&FragTrap::operator=( FragTrap const &rhs ) {

	std::cout << "FragTrap Assignation operator called\n";
	this->ClapTrap::operator=(rhs);
	return (*this);
}

void		FragTrap::attack( std::string const & target ) {

	unsigned int	required_energy = this->Attack_damage;

	if (this->Energy_points >= required_energy) {
		this->Energy_points -= required_energy;
		std::cout << "FragTrap " << this->Name << " attacks " << target
		<< ", causing " << this->Attack_damage
		<< " points of damage!\n";
	}
	else
		std::cout << "FragTrap " << this->Name
		<< " don't have enough energy to attack " << target << ".\n";
}

void 		FragTrap::takeDamage( unsigned int amount ) {

	if (this->Hitpoints >= amount)
		this->Hitpoints -= amount;
	else
		this->Hitpoints = 0;
	std::cout << "FragTrap " << this->Name << " takes " << amount
	<< " points of damage, left " << this->Hitpoints << ".\n";
}

void 		FragTrap::beRepaired( unsigned int amount ) {

	this->Hitpoints += amount;
	std::cout << "FragTrap " << this->Name << " has been repaired with "
	<< amount << " points, " << "current hitpoints are "
	<< this->Hitpoints << ".\n";
}

void		FragTrap::highFivesGuys( void ) {

	std::cout << "Give me a high five!\n";
}
