#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main( void ) {

	Weapon	wep1;
	wep1.setType("BIG_GUN");

	HumanA	hum_a("human1", wep1);
	HumanB	hum_b("human2");

	hum_a.attack();
	hum_b.attack();

	Weapon	wep2("SOME_GUN");
	hum_b.arm(wep2);

	hum_b.attack();

	return (0);
}
