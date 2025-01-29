#include "pipex.h"

int		main()
{
	// int			status;
	// t_cmd		cmd;
	// t_cmd_info	list;
	// pid_t		*pid;

	// list.size = ac - 3;
	// pid = (pid_t *)malloc(sizeof(pid_t) * list.size);
	// init_cmd(&list, &cmd, av, pid);
	// if (access < 0)
	// {
	// 	free;
		
	// }
	// execve
	// if (!a)
	// {
	// 	child func
	// 	exit to not go thru parent func
	// 	exit(11);
	// }
	// else if (a)
	// {
	// 	only parents
	// 	waitpid(a, &status, 0);
	// }
	// printf("%d", status);
	// int	n_fd;
	// n_fd = 3;
	// dup2(1, n_fd);
	// write(n_fd, "hello", 5);
	char	*s = "asdjfa";
	write(0, s, 5);
	// printf("%d", n_fd);
	return (0);
}
