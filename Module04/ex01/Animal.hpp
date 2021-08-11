#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
public:
	Animal( void );
	Animal( Animal const &src );
	virtual	~Animal( void );
	Animal	&operator=( Animal const &rhs );

	virtual	void		makeSound( void ) const;
	std::string const	&getType( void ) const;
protected:
	std::string	type;
};

#endif
