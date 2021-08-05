#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
public:

	ClapTrap( void );
	ClapTrap( std::string const &name );
	ClapTrap( ClapTrap const &src );
	~ClapTrap( void );

	ClapTrap	&operator=( ClapTrap const &rhs );

	void		attack( std::string const & target );
	void 		takeDamage( unsigned int amount );
	void 		beRepaired( unsigned int amount );

protected:
	std::string		Name;
	unsigned int	Hitpoints;
	unsigned int	Energy_points;
	unsigned int	Attack_damage;
};

#endif
