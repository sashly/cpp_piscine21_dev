#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const &name) : name_(name), weapon_(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack() const {

	if (this->weapon_)
		std::cout << this->name_ << " attacks with his "
				  << (this->weapon_)->getType() << "\n";
	else
		std::cout << this->name_ << " cannot attack (has not a weapon);\n";
}

void	HumanB::setWeapon(Weapon const &wep) {

	this->weapon_ = &wep;
}
