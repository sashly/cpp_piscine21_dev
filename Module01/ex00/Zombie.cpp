#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string const &name) : name_(name) {}

Zombie::~Zombie() {

	std::cout << "     ---> Zombie " << this->name_ << " destroyed;\n";
}

void	Zombie::announce() const {

	std::cout << this->name_ << " BraiiiiiiinnnzzzZ...\n";
}
