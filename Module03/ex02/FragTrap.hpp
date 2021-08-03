#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
public:

	FragTrap( void );
	FragTrap( std::string const &name );
	FragTrap( FragTrap const &src );
	~FragTrap( void );

	FragTrap	&operator=( FragTrap const &rhs );

	void		highFivesGuys( void );
};


#endif
