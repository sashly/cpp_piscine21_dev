#include "Weapon.hpp"

Weapon::Weapon() {

	this->weapon_type_ = "unarmed";
}

Weapon::Weapon(std::string const &name) : weapon_type_(name) {}

Weapon::~Weapon() {}

std::string const 	&Weapon::getType() const {

	return (this->weapon_type_);
}

void 				Weapon::setType(std::string const &name) {

	this->weapon_type_ = name;
}
