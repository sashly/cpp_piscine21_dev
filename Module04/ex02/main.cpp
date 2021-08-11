#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( void ) {

	Animal	*i = new Cat();
	Animal	*j = new Dog();
//	Animal	*k = new Animal();
//	Animal	an;

	i->makeSound();
	j->makeSound();
//	k->makeSound();

	delete i;
	delete j;
//	delete k;
	return ( 0 );
}
