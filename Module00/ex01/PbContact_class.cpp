#include "PbContact_class.h"
#include <iostream>

std::string const	&PbContact::get_first_name( void ) const {
	return (this->first_name);
}

std::string const	&PbContact::get_last_name( void ) const {
	return (this->last_name);
}

std::string const	&PbContact::get_nickname( void ) const {
	return (this->nickname);
}

static int	cin_check_eof( void ) {

	if (std::cin.eof()) {
		std::cout << "\n";
		return (1);
	}
	return (0);
}

void	PbContact::set_contact( void ) {

	std::cout << "[first_name]     :> ";
	std::getline(std::cin, this->first_name);
	if (cin_check_eof())
		return ;
	std::cout << "[last_name]      :> ";
	std::getline(std::cin, this->last_name);
	if (cin_check_eof())
		return ;
	std::cout << "[nickname]       :> ";
	std::getline(std::cin, this->nickname);
	if (cin_check_eof())
		return ;
	std::cout << "[phone_number]   :> ";
	std::getline(std::cin, this->phone_number);
	if (cin_check_eof())
		return ;
	std::cout << "[darkest_secret] :> ";
	std::getline(std::cin, this->darkest_secret);
}

void	PbContact::get_contact( void ) const {
	std::cout << "[first_name]     : " << this->first_name << "\n"
			  << "[last_name]      : " << this->last_name << "\n"
			  << "[nickname]       : " << this->nickname << "\n"
			  << "[phone_number]   : " << this->phone_number << "\n"
			  << "[darkest_secret] : " << this->darkest_secret << "\n";
}
