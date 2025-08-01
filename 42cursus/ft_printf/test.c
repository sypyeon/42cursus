
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main()
{
	int	a = 12987398;
	int d;

	d = printf("%");
	ft_printf("%d\n", d);
	d = write(1, "Hello World!", 12);
	ft_printf("%d\n", d);
	return (0);
}