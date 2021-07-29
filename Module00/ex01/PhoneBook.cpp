#include "PhoneBook.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {

	this->contacts_count = 0;
	return ;
}

PhoneBook::~PhoneBook() {}

int	PhoneBook::main_loop( void ) {

	std::string	cmd;

	std::cout << "     --->> Welcome to My Awesome PhoneBook <<---\n"
			  << "         (commands to use: ADD, SEARCH, EXIT)\n";
	while (true) {
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (std::cin.eof()) {
			std::cout << "End of file encountered, exit;\n";
			break ;
		}
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
			this->cmd_add();
		else if (cmd == "SEARCH")
			this->cmd_search();
		else if (cmd == "")
			continue ;
		else
			std::cout << "Error: \"" << cmd << "\" is not a valid command ("
											   "try: ADD, SEARCH or EXIT);\n";
	}
	return (0);
}

void		PhoneBook::cmd_add( void ) {

	int	cnt;

	cnt = this->contacts_count;
	if (this->contacts_count > 7)
		cnt = this->contacts_count % 8;
	this->contacts[cnt].set_contact();
	this->contacts_count++;
}

void		PhoneBook::show_contacts( void ) const {

	int	i;
	int n;

	std::cout << "     ___________________________________________\n"
			  << "    |  index   |first name|last name | nickname |\n"
			  << "    |__________|__________|__________|__________|\n";
	n = (this->contacts_count < 8) ? this->contacts_count : 8;
	for (i = 0; i < n; i++) {
		std::cout << "    |" << std::setw(10) << (i + 1);
		std::cout << "|" << std::setw(10);
		if (this->contacts[i].get_first_name().size() > 10)
			std::cout << this->contacts[i].get_first_name().substr(0, 9) + ".";
		else
			std::cout << this->contacts[i].get_first_name();
		std::cout << "|" << std::setw(10);
		if (this->contacts[i].get_last_name().size() > 10)
			std::cout << this->contacts[i].get_last_name().substr(0, 9) + ".";
		else
			std::cout << this->contacts[i].get_last_name();
		std::cout << "|" << std::setw(10);
		if (this->contacts[i].get_nickname().size() > 10)
			std::cout << this->contacts[i].get_nickname().substr(0, 9) + ".";
		else
			std::cout << this->contacts[i].get_nickname();
		std::cout << "|\n    |__________|__________|__________|__________|\n";
	}
	if (i < 8)
		std::cout << "    |          |          |          |          |\n";
}

void		PhoneBook::cmd_search( void ) const {

	std::string	rem;
	int			index;
	int 		n;

	this->show_contacts();

	std::cout << "Enter index of entry :> ";
	std::cin >> index;
	if (std::cin.eof()) {
		std::cout << "\n";
		return ;
	}
	if (!bool(std::cin)) {
		std::cin.clear();
		std::getline(std::cin, rem);
		std::cout << "Error: wrong input \"" << rem << "\";\n";
		return ;
	}
	std::getline(std::cin, rem);
	n = (this->contacts_count > 7) ? 8 : this->contacts_count;
	if (index < 1 || index > n)
		std::cout << "Error: index is out of range;\n";
	else
		this->contacts[index - 1].get_contact();
}
