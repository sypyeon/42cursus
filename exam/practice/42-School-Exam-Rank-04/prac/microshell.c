#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	ms_exit_w_err_msg(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(STDERR_FILENO, msg + i, 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
	exit (0);
}

void	ms_exit_w_err_msg_and_arg(char *msg, char *arg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(STDERR_FILENO, msg + i, 1);
		i++;
	}
	i = 0;
	while (arg[i])
	{
		write(STDERR_FILENO, arg + i, 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
	exit (0);
}

void	ms_builtin_cd(int ac, char **av)
{
	if (ac != 2)
		ms_exit_w_err_msg("error: cd: bad arguments");
	if (chdir(av[1]) == -1)
		ms_exit_w_err_msg_and_arg("error: cd: cannot change directory to ", av[1]);
	exit (0);
}

void	ms_set_pipe(int *fd, int end)
{
	if (dup2(fd[end], end) == -1)
		ms_exit_w_err_msg("error: fatal");
	if (close(fd[0]))
		ms_exit_w_err_msg("error: fatal");
	if (close(fd[1]))
		ms_exit_w_err_msg("error: fatal");
}

void	ms_child_process(int last, char **av, char **envp, int *fd, int pipe_flag)
{
	av[last] = NULL;
	if (pipe_flag)
		ms_set_pipe(fd, STDOUT_FILENO);
	if (execve(av[0], av, envp) == -1)
		ms_exit_w_err_msg_and_arg("error: cannot execute ", av[0]);
}

int	ms_execute_args(int last, char **av, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		pipe_flag;
	int		status;

	pipe_flag = 0;
	if (av[last] && !strcmp(av[last], "|"))
		pipe_flag = 1;
	if (pipe_flag == 1)
	{
		if (pipe(fd) == -1)
			ms_exit_w_err_msg("error: fatal");
	}
	pid = fork();
	if (pid == -1)
		ms_exit_w_err_msg("error: fatal");
	if (pid == 0)
		ms_child_process(last, av, envp, fd, pipe_flag);
	waitpid(pid, &status, 0);
	if (pipe_flag == 1)
		ms_set_pipe(fd, STDIN_FILENO);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int	status;
	int	count;

	if (ac < 2)
		return (0);
	count = 0;
	while (av[count])
	{
		av += count + 1;
		while (av[count] && strcmp(av[count], "|") && strcmp(av[count], ";"))
			count++;
		if (count)
		{
			if (!strcmp(av[0], "cd"))
				ms_builtin_cd(count, av);
			status = ms_execute_args(count, av, envp);
		}
	}
	return (status);
}