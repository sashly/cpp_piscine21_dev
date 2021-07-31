#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("default_zombie") {}

Zombie::Zombie(std::string const &name) : name(name) {}

Zombie::~Zombie() {

	std::cout << "     ---> Zombie " << this->name << " destroyed;\n";
}

void	Zombie::announce() const {

	std::cout << this->name << " BraiiiiiiinnnzzzZ...\n";
}
