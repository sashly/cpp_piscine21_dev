#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int	replace_open_parse(char **argv, std::ifstream &file,
					   std::ofstream &file_replace) {

	std::string		file_name(argv[1]);
	char 			*tmp;
	unsigned long 	i;

	if (!std::strlen(argv[2]) || !std::strlen(argv[3])) {
		std::cout << "Error: input strings must be non-empty;\n";
		return (0);
	}
	file.open(argv[1]);
	if (!file) {
		std::cout << "Error: cannot open the file \"" << argv[1] << "\"\n";
		return (0);
	}
	file_name += ".replace";
	tmp = new char[file_name.size() + 1];
	if (!tmp) {
		std::cout << "Error: memalloc;\n";
		file.close();
		return (0);
	}
	for (i = 0; i < file_name.size(); i++)
		tmp[i] = file_name[i];
	tmp[i] = '\0';
	file_replace.open(tmp);
	delete [] tmp;
	if (!file_replace) {
		std::cout << "Error: cannot open the .replace file;\n";
		file.close();
		return (0);
	}
	return (1);
}

int	file_to_buf(std::ifstream &file, std::string &buf) {

	std::string	tmp_str;

	while (true) {
		std::getline(file, tmp_str);
		if (file.fail()) {
			std::cout << "Error: I/O error while reading;\n";
			return (0);
		}
		buf += tmp_str;
		if (file.eof())
			break ;
		else
			buf += "\n";
	}
	return (1);
}

int replace_process(std::string const &s1, std::string const &s2,
					std::ifstream &file, std::ofstream &file_replace) {

	std::string	buf;
	size_t	pos_old;
	size_t	pos_new;
	size_t	substr_len;

	if (!file_to_buf(file, buf))
		return (0);
	pos_old = 0;
	while (pos_old < buf.size()) {
		pos_new = buf.find(s1, pos_old);
		if (pos_new == std::string::npos)
			pos_new = buf.size();
		substr_len = pos_new - pos_old;
		file_replace << buf.substr(pos_old, substr_len);
		if (pos_new < buf.size())
			file_replace << s2;
		pos_old = pos_new + s1.size();
	}
	return (1);
}

int	replace_main(char **argv) {

	std::ifstream	file;
	std::ofstream	file_replace;
	std::string		s1;
	std::string		s2;
	int 			ret;

	if (!replace_open_parse(argv, file, file_replace))
		return (0);
	s1 = argv[2];
	s2 = argv[3];
	ret = replace_process(s1, s2, file, file_replace);
	file.close();
	file_replace.close();
	return (ret);
}

int	main(int argc, char **argv) {

	if (argc == 4) {
		if (!replace_main(argv))
			return (1);
	}
	else
		std::cout << "Usage: ./replace <filename> <s1> <s2> (s1, "
					 "s2 are non-empty strings);\n";
	return (0);
}
