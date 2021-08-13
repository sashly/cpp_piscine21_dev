#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
public:
	Brain( void );
	Brain( Brain const &src );
	~Brain( void );
	Brain	&operator=( Brain const &rhs );

	std::string getIdea( int index ) const;
	int 		getIndex( void ) const;
	void		setIdea( std::string const &idea );
	void		printIdeas( void ) const;
private:
	static const int	ideas_size = 100;
	int 				index;
	std::string			ideas[ideas_size];
};

#endif
