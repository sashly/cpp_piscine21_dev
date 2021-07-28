#include "PhoneBook_class.h"
#include <iostream>

PhoneBook::PhoneBook() {

	this->contacts_count = 0;
	return ;
}

PhoneBook::~PhoneBook() {

}

int	PhoneBook::main_loop( void ) {
	std::string	cmd;

	while (true) {
		std::cout << "> ";
		std::cin >> cmd;
		if (std::cin.eof()) {
			std::cout << "End of file encountered, stopping input;\n";
			break ;
		}
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
			this->cmd_add();
		else if (cmd == "SEARCH")
			this->cmd_search();
		else
			std::cout << "Error: \"" << cmd << "\" is discarded;\n";
	}
	return (0);
}

void		PhoneBook::cmd_add( void ) {

	this->contacts[this->contacts_count].set_contact();
}

void		PhoneBook::cmd_search( void ) const {

	std::cout << "SEARCH CMD DO SMTH...\n";
}
