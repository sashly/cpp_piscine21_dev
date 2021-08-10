#include "ClassName.hpp"

ClassName::ClassName( void ) {}

ClassName::ClassName( ClassName const &src ) {}

ClassName::~ClassName( void ) {}

ClassName	&ClassName::operator=( ClassName const &rhs ) {

	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}
