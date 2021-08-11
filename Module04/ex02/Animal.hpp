#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
public:
	Animal( void );
	virtual	~Animal( void );

	virtual	void		makeSound( void ) const = 0;
	std::string const	&getType( void ) const;
protected:
	Animal( Animal const &src );
	Animal	&operator=( Animal const &rhs );

	std::string	type;
};

#endif
