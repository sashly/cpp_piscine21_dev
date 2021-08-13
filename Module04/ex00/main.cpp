#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( void ) {

	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "\n     --> Copy and Assignment operator tests: <--\n";
		Animal *i = new Cat();
		Animal *j = new Dog();
//		Animal *k = new Animal( *i );

//		*i = *j;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
//		k->makeSound();
		delete i;
		delete j;
//		delete k;
	}
	{
		std::cout << "\n     --> WrongAnimal and WrongCat tests: <--\n";
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
	}
	return ( 0 );
}
