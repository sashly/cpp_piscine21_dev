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

	static const int			lvls_n_;
	static std::string const	lvls_[4];
	static  const levels		lvls_ptr_[4];

};

#endif
