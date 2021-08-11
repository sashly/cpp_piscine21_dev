#include "Character.hpp"

Character::Character( void ) {

	for (int i = 0; i < this->inventory_size; i++) {
		this->inventory_equip[i] = false;
		this->inventory[i] = 0;
	}
}

Character::Character( std::string const &n ) : name( n ) {

	for (int i = 0; i < this->inventory_size; i++) {
		this->inventory_equip[i] = false;
		this->inventory[i] = 0;
	}
}

Character::Character( Character const &src ) : name( src.name ) {

	for (int i = 0; i < src.inventory_size; i++) {
		if (src.inventory_equip[i] == true)
			this->inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = 0;
		this->inventory_equip[i] = src.inventory_equip[i];
	}
}

Character::~Character( void ) {

	for (int i = 0; i < this->inventory_size; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

Character	&Character::operator=( Character const &rhs ) {

	if (this != &rhs) {
		this->name = rhs.name;
		for (int i = 0; i < rhs.inventory_size; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			if (rhs.inventory_equip[i] == true)
				this->inventory[i] = rhs.inventory[i]->clone();
			else
				this->inventory[i] = 0;
			this->inventory_equip[i] = rhs.inventory_equip[i];
		}
	}
	return (*this);
}

std::string const	&Character::getName( void ) const {

	return ( this->name );
}

void	Character::equip( AMateria* m ) {

	for (int i = 0; i < this->inventory_size; i++) {
		if (this->inventory_equip[i] == false) {
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = m;
			this->inventory_equip[i] = true;
			break ;
		}
	}
}

void	Character::unequip( int idx ) {

	if (idx >= 0 && idx < 4)
		this->inventory_equip[idx] = false;
}

void	Character::use( int idx, ICharacter& target ) {

	if ((idx >= 0 && idx < 4) && this->inventory_equip[idx] == true)
		this->inventory[idx]->use( target );
}
