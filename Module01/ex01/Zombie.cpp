#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("zombie_default") {}

Zombie::Zombie(std::string const &name) : name(name) {}

Zombie::~Zombie() {

	std::cout << "     ---> Zombie " << this->name << " destroyed;\n";
}

void	Zombie::announce() const {

	std::cout << this->name << " BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::init_default(std::string const &name)
{

	if (this->name == "zombie_default")
		this->name = name;
	else
		std::cerr << "Error: Zombie is already initialized with name: "
				  << this->name << ";\n";
}
