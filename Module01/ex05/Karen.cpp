#include "Karen.hpp"
#include <iostream>

Karen::Karen() {

	this->lvls_n = 4;

	this->lvls = new std::string[4];
	this->lvls[0] = "DEBUG";
	this->lvls[1] = "INFO";
	this->lvls[2] = "WARNING";
	this->lvls[3] = "ERROR";
}

Karen::~Karen() {

	delete [] this->lvls;
}

void	Karen::debug() {

	std::cout << "I love to get extra bacon for my 7XL-double-cheese-"
				 "triple-pickle-special-ketchup burger. I just love it!\n";
}


void	Karen::info() {

	std::cout << "I cannot believe adding extra bacon cost more money. "
				 "You don’t put enough! If you did I would not have "
				 "to ask for it!\n";
}

void	Karen::warning() {

	std::cout << "I think I deserve to have some extra bacon for free. I’ve "
				 "been coming here for years and you just started working"
				 " here last month.\n";
}

void	Karen::error() {

	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

int 	Karen::lvl_index(std::string const &lvl) const {

	for (int i = 0; i < this->lvls_n; i++)
		if (lvl == this->lvls[i])
			return (i);
	return (-1);
}

void	Karen::complain(std::string level) {

	typedef void	(Karen::*levels)( void );
	levels			lvls_p[4];
	int				lvl_ind;

	lvls_p[0] = &Karen::debug;
	lvls_p[1] = &Karen::info;
	lvls_p[2] = &Karen::warning;
	lvls_p[3] = &Karen::error;

	lvl_ind = this->lvl_index(level);
	if (lvl_ind != -1)
		(this->*lvls_p[lvl_ind])();
}
