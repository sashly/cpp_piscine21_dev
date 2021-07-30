#include "Weapon.hpp"

Weapon::Weapon(std::string const &name) : type(name) {}

Weapon::Weapon() {}
Weapon::~Weapon() {}

std::string const 	&Weapon::getType() const {

	return (this->type);
}

void 				Weapon::setType(std::string const &name) {

	this->type = name;
}
