#ifndef	SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
public:

	ScavTrap( void );
	ScavTrap( std::string const &name );
	ScavTrap( ScavTrap const &src );
	~ScavTrap( void );

	ScavTrap	&operator=( ScavTrap const &rhs );

	void		guardGate( void );
};

#endif
