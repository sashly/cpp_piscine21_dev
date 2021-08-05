#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:

	FragTrap( void );
	FragTrap( std::string const &name );
	FragTrap( FragTrap const &src );
	~FragTrap( void );

	FragTrap	&operator=( FragTrap const &rhs );

	void		attack( std::string const & target );
	void 		takeDamage( unsigned int amount );
	void 		beRepaired( unsigned int amount );
	void		highFivesGuys( void );
};

#endif
