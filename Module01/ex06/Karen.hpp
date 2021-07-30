#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen {
public:

	Karen();
	~Karen();

	void	complain(std::string level);

	int 	lvl_index(std::string const &lvl) const;

private:
	typedef void	(Karen::*levels)( void );

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

	int				lvls_n_;
	std::string		lvls_[4];
	levels			lvls_ptr_[4];

};

#endif
