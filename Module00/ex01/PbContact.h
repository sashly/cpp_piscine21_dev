#ifndef PB_CONTACT_H
# define PB_CONTACT_H

# include <string>

class PbContact {
public:

	void	get_contact( void ) const;

	std::string	const	&get_first_name( void ) const;
	std::string const	&get_last_name( void ) const;
	std::string const	&get_nickname( void ) const;

	void	set_contact( void );

private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif
