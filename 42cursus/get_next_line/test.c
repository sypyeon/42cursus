#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	char	*buf;
	int		fd = open("test.txt", O_RDONLY);
	// int		n;

	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		printf("%s", buf);
		free(buf);
	}

	buf = get_next_line(fd);
	printf("%s", buf);
	free(buf);
	buf = get_next_line(fd);
	printf("%s", buf);
	free(buf);
	// buf = get_next_line(fd);
	// printf("%s", buf);
	// free(buf);
	// buf = get_next_line(fd);
	// printf("%s", buf);
	// free(buf);
	// buf = get_next_line(fd);
	// printf("%s", buf);
	// free(buf);

	// n = read(fd, buf, 41);
	// buf[n] = '\0';
	// printf("%s\n", buf);
	// printf("%d\n", n);
	// n = read(fd, buf, 41);
	// buf[n] = '\0';
	// printf("%s\n", buf);
	// printf("%d\n", n);
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