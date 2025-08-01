// if cd with no or without argument
// STDERR "error: cd: bad arguments\n"
// if cd fail
// STDERR "error: cd: cannot change directory to path_to_change\n" followed by a '\n' with path_to_change replaced by the argument to cd## Accepted Files




// - microshell.c

// ## Subject Text

// Allowed functions: 

// > malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp


// ## The Program
// Write a program that will behave like executing a shell command

// - The command line to execute will be the arguments of this program

// - Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)

// - You must implement "|" and ";" like in bash
// 	- we will never try a "|" immediately followed or preceded by nothing or "|" or ";"

// - Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)
// 	- if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'
// 	- if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' with path_to_change replaced by the argument to cd
// 	- a cd command will never be immediately followed or preceded by a "|"

// - You don't need to manage any type of wildcards (*, ~ etc...)

// - You don't need to manage environment variables ($BLA ...)

// - If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in STDERR followed by a '\n' and the program should exit

// - If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n' with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)

// - Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.

// ## Example

// for example this should work:
// ```
// $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
// microshell
// i love my microshell
// $>./microshell /bin/echo WOOT "; /bin/echo NOPE;" "; ;" ";" /bin/echo YEAH
// WOOT ; /bin/echo NOPE; ; ;
// YEAH
// >./microshell 
// ```

// ## Hints
// - Don't forget to pass the environment variable to execve
// - Do not leak file descriptors!

// malloc, free, write, close, fork, waitpid, signal, kill
// exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp

// if cd with no or without argument
// STDERR "error: cd: bad arguments\n"
// if cd fail
// STDERR "error: cd: cannot change directory to path_to_change\n" followed by
// a '\n' with path_to_change replaced by the argument to cd## Accepted Files

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int	exit_with_err_msg(char *msg)
{
	int i = 0;

	while (msg[i])
	{
		write(STDERR_FILENO, msg + i, 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
	exit (1);
}

int	exit_with_err_msg_and_arg(char *msg, char *arg)
{
	int i = 0;

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
	exit (1);
}

int	ms_builtin_cd(int ac, char **av)
{
	if (ac != 2)
		return (exit_with_err_msg("error: cd: bad arguments"));
	if (chdir(av[1]) == -1)
		return (exit_with_err_msg_and_arg("error: cd: cannot change directory to path_to_change ", av[1]));
	exit (0);
}

void	ms_set_pipe(int	*fd, int end)
{
	if (dup2(fd[end], end) == -1)
		exit_with_err_msg("error: fatal");
	if (close(fd[0]) == -1)
		exit_with_err_msg("error: fatal");
	if (close(fd[1]) == -1)
		exit_with_err_msg("error: fatal");
}

void	ms_child_process(char **av, int end, char **envp, int pipe_flag, int *fd)
{
	av[end] = NULL;
	if (pipe_flag)
		ms_set_pipe(fd, STDOUT_FILENO);
	if (execve(av[0], av, envp) == -1)
		exit_with_err_msg_and_arg("error: cannot execute ", av[0]);
}

int	ms_execute_arg(char **av, int end, char **envp)
{
	int	pid;
	int	fd[2];
	int	status;
	int	pipe_flag;

	pipe_flag = 0;
	if (av[end] && !strcmp(av[end], "|"))
		pipe_flag = 1;
	if (pipe_flag)
	{
		if (pipe(fd) == -1)
			exit_with_err_msg("error: fatal");
	}
	pid = fork();
	if (pid == -1)
		exit_with_err_msg("error: fatal");
	if (pid == 0)
		ms_child_process(av, end, envp, pipe_flag, fd);
	waitpid(pid, &status, 0);
	if (pipe_flag)
		ms_set_pipe(fd, STDIN_FILENO);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
}

int	main(int ac, char **av, char **envp)
{
	int	count;
	int	status;

	status = 0;
	count = 0;
	if (ac < 2)
		return (0);
	while (av[count])
	{
		av += count + 1;
		count = 0;
		while (av[count] && strcmp(av[count], "|") && strcmp(av[count], ";"))
			count++;
		if (count > 0)
		{
			if (!strcmp(av[0], "cd"))
				ms_builtin_cd(count, av);
			else
				status = ms_execute_arg(av, count, envp);
		}
	}
	return (status);
}