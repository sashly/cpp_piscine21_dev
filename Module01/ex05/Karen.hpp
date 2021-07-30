#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen {
public:

	Karen();
	~Karen();

	void	complain(std::string level);

private:

	int				lvls_n;
	std::string 	*lvls;

	int 	lvl_index(std::string const &lvl) const;

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif
