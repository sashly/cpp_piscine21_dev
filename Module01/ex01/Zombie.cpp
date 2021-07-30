#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {

	this->name_ = "zombie_default_name";
}

Zombie::Zombie(std::string const &name) : name_(name) {}

Zombie::~Zombie() {

	std::cout << "     ---> Zombie " << this->name_ << " destroyed;\n";
}

void	Zombie::announce() const {

	std::cout << this->name_ << " BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::init_default(std::string const &name)
{

	if (this->name_ == "zombie_default_name")
		this->name_ = name;
	else
		std::cerr << "Error: Zombie is already initialized with name: "
				  << this->name_ << ";\n";
}
