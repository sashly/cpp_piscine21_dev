#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main( void ) {

//	{
//		AMateria *a = new Ice();
//		AMateria *c = new Cure();
//		AMateria *b = a->clone();
//
//		std::cout << a->getType() << "\n";
//		std::cout << b->getType() << "\n";
//		std::cout << c->getType() << "\n";
//
//		delete a;
//		delete b;
//		delete c;
//	}

//	{
//		ICharacter *me = new Character("me");
//
//		me->equip(new Ice());
//		me->equip(new Cure());
//
//		ICharacter *bob = new Character("bob");
//
//		me->use(0, *bob);
//		me->use(1, *bob);
//
//		delete bob;
//		delete me;
//	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria( new Ice() );
		src->learnMateria( new Cure() );

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	return ( 0 );
}
