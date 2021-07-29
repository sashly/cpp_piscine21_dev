#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "PbContact_class.h"

class PhoneBook {
public:

	PhoneBook( void );
	~PhoneBook( void );

	int			main_loop( void );

private:

	void		cmd_add( void );
	void		cmd_search( void ) const;

	void		show_contacts( void ) const;

	PbContact	contacts[8];
	int			contacts_count;
};

#endif
