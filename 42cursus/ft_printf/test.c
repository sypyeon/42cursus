
#include <stdarg.h>
#include <stdio.h>
#include "./libft/libft.h"

void	print_numbers(int count, ...)
{
	int		i;
	va_list	args;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		printf("%d\n", va_arg(args, int));
		i++;
	}
	va_end(args);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
}

int	main(void)
{
	int d;
	char c;
	char *s;

	d = 1515;
	c = 'c';
	s = "Hello World";
	printf("%c\n", c);
	printf("%s\n", s);
	printf("%p\n", s);
	printf("%d\n", d);
	printf("%i\n", d);
	printf("%u\n", d);
	printf("%x\n", d);
	printf("%X\n", d);
	printf("%%\n", d);
	return (0);
}