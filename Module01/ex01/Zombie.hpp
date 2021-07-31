#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
public:

	Zombie( void );
	Zombie(std::string const &name);
	~Zombie( void );

	void	announce( void ) const;

	void	init_default(std::string const &name);

private:
	std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
