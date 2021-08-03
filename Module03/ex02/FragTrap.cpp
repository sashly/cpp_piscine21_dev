#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) {
	std::cout << "Default FragTrap constructor called\n"; }

FragTrap::FragTrap( std::string const &name ) : ClapTrap( name ) {

	std::cout << "Name FragTrap constructor called\n";
	this->Hitpoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap( FragTrap const &src ) {

	std::cout << "Copy FragTrap constructor called\n";
	*this = src;
}

FragTrap::~FragTrap( void ) { std::cout << "FragTrap Destructor called\n"; }

FragTrap	&FragTrap::operator=( FragTrap const &rhs ) {

	(void)rhs;
	std::cout << "FragTrap Assignation operator called\n";
	return (*this);
}

void		FragTrap::highFivesGuys( void ) {

	std::cout << "Give me a high five!\n";
}
