#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

int	main( void ) {

	Animal	*i = new Cat();
	Brain	brain;
	Animal	*j = new Cat( brain );

	Cat		cat;
	Animal	*k = new Cat( cat );

	i->makeSound();
	k->makeSound();

	delete i;
	delete j;
	delete k;
	return ( 0 );
}
