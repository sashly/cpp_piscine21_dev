#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
public:

	DiamondTrap( void );
	DiamondTrap( std::string const &name );
	DiamondTrap( DiamondTrap const &src );
	~DiamondTrap( void );

	DiamondTrap	&operator=( DiamondTrap const &rhs );

	void		whoAmI( void );
};


#endif
