#include "Karen.hpp"
#include <iostream>

const int			Karen::lvls_n_ = 4;

std::string const	Karen::lvls_[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

const Karen::levels	Karen::lvls_ptr_[4] = { &Karen::debug, &Karen::info,
											   &Karen::warning, &Karen::error };

Karen::Karen() {}
Karen::~Karen() {}

void	Karen::debug() {

	std::cout << "I love to get extra bacon for my 7XL-double-cheese-"
				 "triple-pickle-special-ketchup burger.\nI just love it!\n";
}

void	Karen::info() {

	std::cout << "I cannot believe adding extra bacon cost more money.\n"
				 "You don’t put enough! If you did I would not have "
				 "to ask for it!\n";
}

void	Karen::warning() {

	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve "
				 "been coming here for years and you just started working"
				 " here last month.\n";
}

void	Karen::error() {

	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

int 	Karen::lvl_index(std::string const &lvl) const {

	for (int i = 0; i < this->lvls_n_; i++)
		if (lvl == this->lvls_[i])
			return (i);
	return (-1);
}

void	Karen::complain(std::string level) {

	int				lvl_ind;

	lvl_ind = this->lvl_index(level);
	if (lvl_ind != -1)
		(this->*lvls_ptr_[lvl_ind])();
}
