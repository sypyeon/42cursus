#include <stdio.h>
#include "so_long.h"

int	main(int ac, char **av)
{
	char *e = "dummy.c";
	int fd = open(e, O_RDONLY);
	if (fd < 0)
	{
		perror(e);
		exit(errno);
	}
	
	// e = strerror(errno);
	while (ac)
		break ;
	printf("%s\n", av[0]);
	// printf("%s\n", e);
	close(fd);
	return (100);
}