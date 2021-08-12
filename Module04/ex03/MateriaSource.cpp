#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {

	this->count = 0;
	for (int i = 0; i < this->storage_size; i++) {
		this->storage[i] = 0;
		this->dub[i] = false;
	}
}

MateriaSource::MateriaSource( MateriaSource const &src ) {

	this->count = src.count;
	for (int i = 0; i < src.storage_size; i++) {
		if (src.storage[i])
			this->storage[i] = src.storage[i];
		else
			this->storage[i] = 0;
		this->dub[i] = (this->storage[i]);
	}
}

MateriaSource::~MateriaSource( void ) {

	for (int i = 0; i < this->storage_size; i++)
		if (this->storage[i] && this->dub[i] == false) {
			delete this->storage[i];
		}
}

MateriaSource	&MateriaSource::operator=( MateriaSource const &rhs ) {

	if (this != &rhs) {
		this->count = rhs.count;
		for (int i = 0; i < rhs.storage_size; i++) {
			if (this->storage[i] && this->dub[i] == false)
				delete this->storage[i];
			if (rhs.storage[i])
				this->storage[i] = rhs.storage[i];
			else
				this->storage[i] = 0;
			this->dub[i] = (this->storage[i]);
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria *m ) {

	bool	dub_flag;

	dub_flag = false;
	if (!m || this->count == 4)
		return ;
	for (int i = 0; i < this->storage_size; i++)
		if (this->storage[i] == m)
			dub_flag = true;
	for (int i = 0; i < this->storage_size; i++) {
		if (this->storage[i] == 0) {
			this->storage[i] = m;
			this->dub[i] = dub_flag;
			this->count++;
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
