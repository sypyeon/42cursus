#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	int	i = 1;
	std::string	str;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (av[i])
	{
		str += av[i];
		i++;
	}
	for (unsigned long j = 0; j < str.length(); j++)
	{
		str[j] = std::toupper(str[j]);
	}
	std::cout << str << std::endl;
}
