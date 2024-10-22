#include "ft_printf.h"
#include <stdio.h>

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

int	main(void)
{
	int d;
	int	word;
	char c;
	char *s;

	word = write(1, "hi", 2);
	d = 1515;
	c = 'c';
	s = "Hello World";
	printf("%d\n", word);
	printf("%c\n", c);
	printf("%s\n", s);
	printf("%p\n", s);
	printf("%d\n", d);
	printf("%i\n", d);
	printf("%u\n", d);
	printf("%x\n", d);
	printf("%X\n", d);
	return (0);
}