#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
public:
	Cat( void );
	Cat( Brain const &brain );
	Cat( Cat const &src );
	virtual	~Cat( void );

	Cat	&operator=( Cat const &rhs );

	virtual	void	makeSound( void ) const;

	void		setIdea( std::string const &idea );
	void		printIdeas( void ) const;
private:
	Brain	*brain;
	void	deepCopy( Cat const &src );
};

#endif
