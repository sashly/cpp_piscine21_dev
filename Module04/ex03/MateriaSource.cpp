#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {

	for (int i = 0; i < this->storage_size; i++)
		this->storage[i] = 0;
}

MateriaSource::MateriaSource( MateriaSource const &src ) {

	for (int i = 0; i < src.storage_size; i++) {
		if (src.storage[i])
			this->storage[i] = src.storage[i]->clone();
		else
			this->storage[i] = 0;
	}
}

MateriaSource::~MateriaSource( void ) {

	for (int i = 0; i < this->storage_size; i++)
		if (this->storage[i])
			delete this->storage[i];
}

MateriaSource	&MateriaSource::operator=( MateriaSource const &rhs ) {

	if (this != &rhs) {
		for (int i = 0; i < rhs.storage_size; i++) {
			if (this->storage[i])
				delete this->storage[i];
			if (rhs.storage[i])
				this->storage[i] = rhs.storage[i]->clone();
			else
				this->storage[i] = 0;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria *m ) {

	for (int i = 0; i < this->storage_size; i++) {
		if (this->storage[i] == 0) {
			this->storage[i] = m->clone();
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria( std::string const & type ) {

	for (int i = 0; i < this->storage_size; i++) {
		if (this->storage[i] && (this->storage[i]->getType() == type))
			return ( this->storage[i]->clone() );
	}
	return ( 0 );
}
