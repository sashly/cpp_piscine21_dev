#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <unistd.h>

int	main( void ) {

	{
		std::cout << "       --> DEEP COPY TESTS: <--\n";
		Cat	*cat = new Cat();
		cat->setIdea( "idea_one" );
		cat->setIdea( "idea_two" );
		cat->setIdea( "idea_three" );
		cat->printIdeas();
		Cat copy_cat( *cat );
		Cat assign_cat;
		assign_cat = *cat;
		delete cat;
		copy_cat.printIdeas();
		assign_cat.printIdeas();

		Dog	basic;
		basic.setIdea( "one" );
		basic.setIdea( "two" );
		basic.setIdea( "three" );
		basic.printIdeas();
		{
			Dog tmp = basic;
		}
		basic.printIdeas();
	}
	{
		std::cout << "\n       --> LEAKS TESTS: <--\n";
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	{
		std::cout << "\n       --> MAIN TESTS: <--\n";
		int const	arr_size = 8;
		Animal		**arr = new Animal*[arr_size];
//		Animal		*arr[arr_size];

		for (int i = 0; i < arr_size; i++) {
			if (i % 2)
				arr[i] = new Cat();
			else
				arr[i] = new Dog();
		}
		for (int i = 0; i < arr_size; i++)
			arr[i]->makeSound();
		for (int i = 0; i < arr_size; i++)
			delete arr[i];
		delete [] arr;
	}
	{
		std::cout << "       --> ANIMAL CLASS INSTANTIATION: <--\n";
		Animal	an;
		Animal	*k = new Animal();
		an.makeSound();
		k->makeSound();
		delete k;
	}

	sleep(5);
	return ( 0 );
}
