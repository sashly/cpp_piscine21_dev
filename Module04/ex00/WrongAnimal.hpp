#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class WrongAnimal {
public:
	WrongAnimal( void );
	WrongAnimal( WrongAnimal const &src );
	~WrongAnimal( void );

	WrongAnimal	&operator=( WrongAnimal const &rhs );

	void				makeSound( void ) const;
	std::string const	&getType( void ) const;
protected:
	std::string	type;
};

#endif
