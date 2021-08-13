#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {

	this->count = 0;
	for (int i = 0; i < this->storage_size; i++) {
		this->storage[i] = 0;
		this->dub[i] = false;
	}
}

MateriaSource::MateriaSource( MateriaSource const &src ) {

	this->count = src.getCount();
	for (int i = 0; i < src.storage_size; i++) {
		if (src.getStorage( i ))
			this->storage[i] = src.getStorage( i );
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
			if (rhs.getStorage( i ))
				this->storage[i] = rhs.getStorage( i );
			else
				this->storage[i] = 0;
			this->dub[i] = (this->storage[i]);
		}
	}
	return ( *this );
}

int	MateriaSource::getCount( void ) const {

	return ( this->count );
}

AMateria	*MateriaSource::getStorage( int index ) const {

	return ( this->storage[index] );
}

bool	MateriaSource::getDub( int index ) const {

	return ( this->dub[index] );
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
