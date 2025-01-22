#include <iostream>
#include <string>

void	str_toupper(std::string str)
{
	int		i;
	char	c;

	i = 0;
	while(i < str.size())
	{
		std::cout << (char)toupper(str[i++]);
	}
}


int	main(int argc, char **argv)
{
	int			i;
	std::string	str;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
		str_toupper(argv[i++]);
	std::cout << std::endl;
	return (0);
}