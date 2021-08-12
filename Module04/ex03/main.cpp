#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main( void ) {

	{
		std::cout << "       --> MATERIA COPY AND ASSIGN TESTS: <--\n";
		//	this way we only assign the type string, but the VPTR and VTABLE
		//	stay old (i.e. assigning ice to cure we have new type string,
		//	but old methods with appropriate outputs);

		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");

		AMateria	*ice = new Ice();
		AMateria	*cure = new Cure();

//		*cure = *ice;
		std::cout << cure->getType() << "\n";
		me->equip( cure );
		me->equip( ice );
		me->use( 0, *bob );
		me->use( 1, *bob );

		delete me;
		delete bob;
	}
	{
		std::cout << "\n       --> EQUIP AND UNEQUIP TESTS: <--\n";
		ICharacter	*me = new Character("me");
		ICharacter	*bob = new Character("bob");
		AMateria	*ice = new Ice();
		AMateria	*cure = new Cure();

		me->equip( cure );
		me->equip( ice );
		me->equip( cure );
		me->unequip( 0 );
		me->unequip( 1 );
		me->unequip( 1 );
		me->equip( ice );
		bob->equip( cure );

		std::cout << "\n";
		me->use( 1, *bob );
		me->use( 0, *bob );
		bob->use( 0, *bob );
		bob->use( 0, *me );

		std::cout << "\n";
		me->unequip( 0 );
		bob->unequip( 0 );
		delete ice;
		delete cure;

		delete me;
		delete bob;
	}
	{
		std::cout << "\n       --> CHARACTER DEEP COPY TESTS: <--\n";
		Character	me( "me" );
		AMateria	*cure = new Cure();
		AMateria	*ice = new Ice();
		AMateria	*ice1 = new Ice();
		me.equip( cure );
		me.equip( ice );

		Character 	bob( me );
		Character	tom( "tom" );
		tom.equip( ice1 );
		tom = bob;

		me.unequip( 0 );
		me.unequip( 1 );
		delete cure;
		delete ice;

		std::cout << "\n";
		bob.use( 1, me );
		tom.use( 0, me );
	}
	{
		std::cout << "\n       --> MATERIASOURCE TESTS: <--\n";

		MateriaSource	*src = new MateriaSource();
		AMateria		*tmp = new Cure();

		src->learnMateria( tmp );
		src->learnMateria( tmp );
		src->learnMateria( tmp );
		src->learnMateria( tmp );
		src->learnMateria( tmp );

		MateriaSource	src1( *src );
		MateriaSource	src2;
		src2 = *src;

		AMateria	*tmp1;
		tmp1 = src1.createMateria( "cure" );
		std::cout << tmp1->getType() << "\n";
		delete tmp1;

		delete src;
	}
	{
		std::cout << "\n       --> SUBJECT TESTS: <--\n";
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
