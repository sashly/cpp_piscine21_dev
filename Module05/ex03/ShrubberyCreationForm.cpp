#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm( void )
		: Form( "ShrubberyCreationForm", 145, 137 ), target( "" ) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &t )
		: Form( "ShrubberyCreationForm", 145, 137 ), target( t ) {}

ShrubberyCreationForm::ShrubberyCreationForm(
		ShrubberyCreationForm const &src ) : Form( src ),
											 target( src.getTarget() ) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(
								ShrubberyCreationForm const &rhs ) {

	(void)rhs;
	return (*this);
}

std::string const	&ShrubberyCreationForm::getTarget( void ) const {

	return ( this->target );
}

void	ShrubberyCreationForm::action( void ) const {

	std::ofstream	file;
	std::string		file_name;
	char 			*name;

	file_name += this->getTarget();
	file_name += "_shrubbery";
	name = new char[file_name.size() + 1];
	for (size_t i = 0; i < file_name.size(); i++)
		name[i] = file_name[i];
	name[file_name.size()] = '\0';
	file.open( name );
	delete [] name;
	if (!file)
		throw ( ShrubberyCreationForm::ExecOpenFileException() );
	file << "                      ___\n"
	<< "                _,-'\"\"   \"\"\"\"`--.\n"
	<< "             ,-'          __,,-- \\\n"
	<< "           ,'    __,--\"\"\"\"dF      )\n"
	<< "          /   .-\"Hb_,--\"\"dF      /\n"
	<< "        ,'       _Hb ___dF\"-._,-'\n"
	<< "      ,'      _,-\"\"\"\"   \"\"--..__\n"
	<< "     (     ,-'                  `.\n"
	<< "      `._,'     _   _             ;\n"
	<< "       ,'     ,' `-'Hb-.___..._,-'\n"
	<< "       \\    ,'\"Hb.-'HH`-.dHF\"\n"
	<< "        `--'   \"Hb  HH  dF\"\n"
	<< "                \"Hb HH dF\n"
	<< "                 \"HbHHdF\n"
	<< "                  |HHHF\n"
	<< "                  |HHH|\n"
	<< "                  |HHH|\n"
	<< "                  |HHH|\n"
	<< "                  |HHH|\n"
	<< "                  dHHHb\n"
	<< "                .dFd|bHb.               o\n"
	<< "      o       .dHFdH|HbTHb.          o /\n"
	<< "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
	<< "##########################################\n";
	file.close();
}
