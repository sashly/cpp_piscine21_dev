#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
class AMateria;
class ICharacter;
# include "ICharacter.hpp"

class AMateria {
public:
	AMateria( void );
	AMateria( std::string const &type );
	virtual ~AMateria( void );

	std::string const	&getType( void ) const;
	virtual AMateria	*clone( void ) const = 0;
	virtual void 		use( ICharacter& target );
protected:
	AMateria( AMateria const &src );
	AMateria	&operator=( AMateria const &rhs );

	std::string	type;
};

#endif

