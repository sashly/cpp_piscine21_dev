#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const &name) : name_(name) {}

HumanB::~HumanB() {}

void	HumanB::attack() const {

	if ((this->weapon_).getType() == "unarmed")
		std::cout << this->name_ << " cannot attack, he has not a weapon;\n";
	else
		std::cout << this->name_ << " attacks with his "
				  << (this->weapon_).getType() << "\n";
}

void	HumanB::arm(const Weapon &weapon) {

	this->weapon_ = weapon;
}
