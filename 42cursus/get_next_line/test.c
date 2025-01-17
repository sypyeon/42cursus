#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	char	*buf;
	int		fd = open("test.txt", O_RDONLY);

	while (1)
	// for(int i = 0; i < 20; ++i)
	{
		buf = get_next_line(fd);
		printf("%s", buf);
		if (buf)
			free(buf);
	}


	// int	i = 0;
	// while (i < 10)
	// {
	// 	buf = get_next_line(fd);
	// 	printf("%s", buf);
	// 	free(buf);
	// 	i++;
	// }

	// int		n;
	// n = read(fd, buf, 41);
	// buf[n] = '\0';
	// printf("%s\n", buf);
	// printf("%d\n", n);
	
	// n = 1;
	// while(n)
	// {
	// 	n = read(fd, buf, 2);
	// 	buf[n] = '\0';
	// 	printf("%s", buf);
	// 	// printf("%d", n);
	// }

	close(fd);

	
	return (0);
}
