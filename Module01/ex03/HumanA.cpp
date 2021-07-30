#include "HumanA.hpp"
#include <iostream>

//NAME attacks with his WEAPON_TYPE

HumanA::HumanA(std::string const &name, Weapon const &wep) : name_(name),
													 	     weapon_(wep) {}

HumanA::~HumanA() {}

void	HumanA::attack() const {

	std::cout << this->name_ << " attacks with his "
			  << (this->weapon_).getType() << "\n";
}
