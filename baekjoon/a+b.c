#include<stdio.h>

int	main(int ac, char** av)
{
	int a = (int)av[2] - '0';
	int b = (int)av[3] - '0';
	printf("%d", a + b);
	return 0;
}