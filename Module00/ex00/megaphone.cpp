#include <iostream>

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(int argc, char **argv)
{
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++)
				std::cout << ft_toupper(argv[i][j]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
