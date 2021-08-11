#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource( void );
	MateriaSource( MateriaSource const &src );
	virtual ~MateriaSource( void );
	MateriaSource	&operator=( MateriaSource const &rhs );

	virtual void		learnMateria( AMateria* );
	virtual AMateria*	createMateria( std::string const & type );
private:
	static int const	storage_size = 4;
	AMateria			*storage[storage_size];
	int 				count;
	bool				dub[storage_size];
};

#endif
