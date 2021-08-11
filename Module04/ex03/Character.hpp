#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character : public ICharacter {
public:
	Character( void );
	Character( std::string const &name );
	Character( Character const &src );
	virtual ~Character( void );
	Character	&operator=( Character const &rhs );

	virtual	std::string const	&getName( void ) const;
	virtual void				equip( AMateria* m );
	virtual void				unequip( int idx );
	virtual void				use( int idx, ICharacter& target );

private:
	std::string			name;

	static int const	inventory_size = 4;
	AMateria			*inventory[inventory_size];
	bool 				inventory_equip[inventory_size];
};

#endif
