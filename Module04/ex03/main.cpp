#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main( void ) {

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
//	{
//		IMateriaSource* src = new MateriaSource();
//		src->learnMateria( new Ice() );
//		src->learnMateria( new Cure() );
//
//		ICharacter* me = new Character("me");
//
//		AMateria* tmp;
//		tmp = src->createMateria("ice");
//		me->equip(tmp);
//		tmp = src->createMateria("cure");
//		me->equip(tmp);
//
//		ICharacter* bob = new Character("bob");
//
//		me->use(0, *bob);
//		me->use(1, *bob);
//
//		delete bob;
//		delete me;
//		delete src;
//	}

//	{
//		//	Materia copy and ASSIGNING tests:
//		//	this way we only assign the type string, but the VPTR and VTABLE
//		//	stay old (i.e. assigning ice to cure we have new type string,
//		//	but old methods with appropriate outputs);
//
//		ICharacter* me = new Character("me");
//		ICharacter* bob = new Character("bob");
//
//		AMateria	*ice = new Ice();
//		AMateria	*cure = new Cure();
//
////		*cure = *ice;
//		std::cout << cure->getType() << "\n";
//		me->equip( cure );
//		me->equip( ice );
//		me->use( 0, *bob );
//		me->use( 1, *bob );
//
//		delete me;
//		delete bob;
//	}

	{
		//	Not unique materia tests:
		IMateriaSource	*src = new MateriaSource();
		AMateria		*tmp = new Cure();

		src->learnMateria( tmp );
		src->learnMateria( tmp );

		delete src;
	}


	return ( 0 );
}
