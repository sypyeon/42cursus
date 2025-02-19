
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main()
{
	unsigned int	i = 0;
	int	max;

	char *max_str = (char *)malloc(sizeof(char) * INT_MAX + 1);
	if (!max_str)
		return 0;
	while (i <= INT_MAX)
	{
		max_str[i] = 'a';
		i++;
	}
	max = ft_printf("%s", max_str);
	printf("%d\n", max);
	return (0);
}