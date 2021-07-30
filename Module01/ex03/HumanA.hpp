#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {
public:

	HumanA(std::string const &name, Weapon wep);
	~HumanA();

	void	attack( void ) const;

private:
	std::string	name_;
	Weapon		weapon_;
};

#endif
