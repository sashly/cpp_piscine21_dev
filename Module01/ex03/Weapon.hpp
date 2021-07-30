#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
public:

	Weapon(std::string const &name);

	Weapon( void );
	~Weapon( void );

	std::string const 	&getType( void ) const;
	void 				setType(std::string const &name);

private:
	std::string	weapon_type_;
};


#endif
