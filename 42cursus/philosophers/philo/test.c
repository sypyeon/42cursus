# include "philo.h"
# include <unistd.h>

int main(int ac, char **av)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);

    printf("Seconds: %ld\n", tv.tv_sec);
    printf("Microseconds: %ld\n", tv.tv_usec);
	return (ac);
}