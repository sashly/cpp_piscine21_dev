#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {
public:

	HumanB(std::string const &name);
	~HumanB();

	void	attack( void ) const;

	void	setWeapon(Weapon const &wep);

private:
	std::string		name_;
	Weapon const	*weapon_;
};

#endif
