#include "PbContact_class.h"
#include <iostream>

void	PbContact::get_first_name( void ) const {
	std::cout << this->first_name;
}

void	PbContact::get_last_name( void ) const {
	std::cout << this->last_name;
}

void	PbContact::get_nickname( void ) const {
	std::cout << this->nickname;
}

void	PbContact::set_contact( void ) {

	std::cout << "[first_name]     :> ";
	std::cin >> this->first_name;
	std::cout << "[last_name]      :> ";
	std::cin >> this->last_name;
	std::cout << "[nickname]       :> ";
	std::cin >> this->nickname;
	std::cout << "[phone_number]   :> ";
	std::cin >> this->phone_number;
	std::cout << "[darkest_secret] :> ";
	std::cin >> this->darkest_secret;
}

void	PbContact::get_contact( void ) const {
	std::cout << "[first_name]     : " << this->first_name << "\n"
			  << "[last_name]      : " << this->last_name << "\n"
			  << "[nickname]       : " << this->nickname << "\n"
			  << "[phone_number]   : " << this->phone_number << "\n"
			  << "[darkest_secret] : " << this->darkest_secret << "\n";
}
