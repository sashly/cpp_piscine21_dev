#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

int	main( void ) {

	Animal	*i = new Cat();
	Brain	brain;
	Animal	*j = new Cat( brain );

	i->makeSound();

	delete i;
	delete j;
	return ( 0 );
}
