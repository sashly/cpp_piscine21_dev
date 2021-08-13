#include "Character.hpp"
#include <iostream>

Character::Character( void ) {

	for (int i = 0; i < this->inventory_size; i++)
		this->inventory[i] = 0;
}

Character::Character( std::string const &n ) : name( n ) {

	for (int i = 0; i < this->inventory_size; i++)
		this->inventory[i] = 0;
}

Character::Character( Character const &src ) : name( src.getName() ) {

	for (int i = 0; i < src.inventory_size; i++) {
		if (src.getInventory( i ))
			this->inventory[i] = src.getInventory( i )->clone();
		else
			this->inventory[i] = 0;
	}
}

Character::~Character( void ) {

	for (int i = 0; i < this->inventory_size; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

Character	&Character::operator=( Character const &rhs ) {

	if (this != &rhs) {
		this->name = rhs.getName();
		for (int i = 0; i < rhs.inventory_size; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			if (rhs.getInventory( i ))
				this->inventory[i] = rhs.getInventory( i )->clone();
			else
				this->inventory[i] = 0;
		}
	}
	return (*this);
}

std::string const	&Character::getName( void ) const {

	return ( this->name );
}

AMateria const	*Character::getInventory( int index ) const {

	return ( this->inventory[index] );
}


void	Character::equip( AMateria* m ) {

	if (!m)
		return ;
	for (int i = 0; i < this->inventory_size; i++) {
		if (this->inventory[i] == m) {
			std::cout << this->getName()
					  << ": this Materia is already equipped;\n";
			return ;
		}
	}
	for (int i = 0; i < this->inventory_size; i++) {
		if (this->inventory[i] == 0) {
			this->inventory[i] = m;
			std::cout << this->getName() << ": equip " << m->getType()
					  << " materia at " << i << " slot in inventory;\n";
			return ;
		}
	}
	std::cout << this->getName()
			  << ": cannot equip - inventory is already full;\n";
}

void	Character::unequip( int idx ) {

	if ((idx >= 0 && idx < 4) && this->inventory[idx] != 0) {
		std::cout << this->getName() << ": unequip "
				  << this->inventory[idx]->getType() << " materia from "
				  << idx << " slot in inventory;\n";
		this->inventory[idx] = 0;
	}
	else
		std::cout << this->getName() << ": cannot unequip materia from "
				  << idx << " slot in inventory;\n";
}

void	Character::use( int idx, ICharacter& target ) {

	if ((idx >= 0 && idx < this->inventory_size)
			&& this->inventory[idx] != 0)
		this->inventory[idx]->use( target );
	else
		std::cout << this->getName() << ": cannot use materia from "
				  << idx << " slot on " << target.getName() << ";\n";
}

