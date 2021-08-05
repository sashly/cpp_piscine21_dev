#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : private ScavTrap, private FragTrap {
public:

	DiamondTrap( void );
	DiamondTrap( std::string const &name );
	DiamondTrap( DiamondTrap const &src );
	~DiamondTrap( void );

	DiamondTrap	&operator=( DiamondTrap const &rhs );

	void		whoAmI( void );

	using ScavTrap::attack;
	using ScavTrap::guardGate;
	using FragTrap::highFivesGuys;

	void		debug( void ) const;

private:
	std::string	Name;
};

#endif
