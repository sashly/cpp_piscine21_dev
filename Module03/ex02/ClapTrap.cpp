#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) {
	std::cout << "Default ClapTrap constructor called\n"; }

ClapTrap::ClapTrap( std::string const &name ) : Name( name ),
												Hitpoints( 10 ),
												Energy_points( 10 ),
												Attack_damage( 0 ) {
	std::cout << "Name ClapTrap constructor called\n";
}

ClapTrap::ClapTrap( ClapTrap const &src ) {

	std::cout << "Copy ClapTrap constructor called\n";
	*this = src;
}

ClapTrap::~ClapTrap( void ) { std::cout << "ClapTrap Destructor called\n"; }

ClapTrap	&ClapTrap::operator=( ClapTrap const &rhs ) {

	std::cout << "ClapTrap Assignation operator called\n";
	this->Name = rhs.Name;
	this->Hitpoints = rhs.Hitpoints;
	this->Energy_points = rhs.Energy_points;
	this->Attack_damage = rhs.Attack_damage;
	return (*this);
}

void		ClapTrap::attack( std::string const & target ) {

	unsigned int	required_energy = this->Attack_damage;

	if (this->Energy_points >= required_energy) {
		this->Energy_points -= required_energy;
		std::cout << "ClapTrap " << this->Name << " attacks " << target
				  << ", causing " << this->Attack_damage
				  << " points of damage!\n";
	}
}

void 		ClapTrap::takeDamage( unsigned int amount ) {

	if (this->Hitpoints >= amount)
		this->Hitpoints -= amount;
	else
		this->Hitpoints = 0;
	std::cout << "ClapTrap " << this->Name << " takes " << amount
			  << " points of damage, left " << this->Hitpoints << ".\n";
}

void 		ClapTrap::beRepaired( unsigned int amount ) {

	this->Hitpoints += amount;
	std::cout << "ClapTrap " << this->Name << " has been repaired with "
			  << amount << " points, " << "current hitpoints are "
			  << this->Hitpoints << ".\n";
}
