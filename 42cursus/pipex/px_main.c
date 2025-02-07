/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:37:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/07 15:57:29 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "pipex.h"

void	px_close_fd(t_cmd *node, t_cmd_info *list)
{
	if (node->fd[0])
		close(node->fd[0]);
	if (node->fd[1])
		close(node->fd[1]);
	if (list->in_fd)
		close(list->in_fd);
	if (list->out_fd)
		close(list->out_fd);
}

void	px_parent(t_cmd_info *list, pid_t *pid)
{
	int	i = 0;

	while (i < list->size)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	// free_func;
}

void	px_child_execve(t_cmd *node, t_cmd_info *list, char **envp)
{
	if (node->prev)
	{
		dup2(node->prev->fd[0], STDIN_FILENO);
		close(node->prev->fd[0]);
		close(node->prev->fd[1]);
	}
	else
		dup2(list->in_fd, STDIN_FILENO);
	close(list->in_fd);
	if (node->next)
	{
		dup2(node->fd[1], STDOUT_FILENO);
		close(node->fd[0]);
		close(node->fd[1]);
	}
	else
		dup2(list->out_fd, STDOUT_FILENO);
	close(list->out_fd);
	if (execve(node->cmd[0], node->cmd, envp) == -1)
	{
		perror(node->cmd[0]);
		// freefunc;
		exit(errno);
	}
}

void	px_child(t_cmd *node, t_cmd_info *list, char **envp, pid_t *pid)
{
	int	i;

	i = 0;
	while (node)
	{
		if (node->next)
			pipe(node->fd);
		pid[i] = fork();
		if (pid[i] == 0)
			px_child_execve(node, list, envp);
		if (node->prev)
		{
			close(node->prev->fd[0]);
			close(node->prev->fd[1]);
		}
		node = node->next;
		i++;
	}
}

void	px_new_child(t_cmd *node, t_cmd_info *list)
{
	int		hd_fd[2];
	pid_t	hd_pid;
	int		read_len;
	char	buf[100000];

	pipe(hd_fd);
	hd_pid = fork();
	if (hd_pid == 0)
	{
		while (1)
		{
			read_len = read(STDIN_FILENO, buf, 100000);
			buf[read_len] = '\0';
			if (ft_strncmp(list->limiter, buf, read_len) == 0)
				break;
			write(hd_fd[1], buf, read_len);
		}
		px_close_fd(node, list);
		close(hd_fd[0]);
		close(hd_fd[1]);
		// freefunc
		exit(0);
	}
	dup2(hd_fd[0], STDIN_FILENO);
	close(hd_fd[0]);
	close(hd_fd[1]);
	waitpid(hd_pid, NULL, 0);
	// freefunc
}

void	px_hd_child(t_cmd *node, t_cmd_info *list, char **envp)
{
	if (node->prev)
	{
		dup2(node->prev->fd[0], STDIN_FILENO);
		close(node->prev->fd[0]);
		close(node->prev->fd[1]);
	}
	else
		px_new_child(node, list);
	if (node->next)
	{
		dup2(node->fd[1], STDOUT_FILENO);
		close(node->fd[0]);
		close(node->fd[1]);
	}
	else
		dup2(list->out_fd, STDOUT_FILENO);
	close(list->out_fd);
	if (execve(node->cmd[0], node->cmd, envp) == -1)
	{
		perror(node->cmd[0]);
		// freefunc
		exit(errno);
	}
}

void	px_here_doc(t_cmd *node, t_cmd_info *list, char **envp, pid_t *pid)
{
	int	i;

	i = 0;
	while (node)
	{
		if (node->next)
			pipe(node->fd);
		pid[i] = fork();
		if (pid[i] == 0)
			px_hd_child(node, list, envp);
		if (node->prev)
		{
			close(node->prev->fd[0]);
			close(node->prev->fd[1]);
		}
		node = node->next;
		i++;
	}
}

void	px_free_node(t_cmd *node)
{
	int	i;

	i = 0;
	if (!node->cmd)
		return ;
	while (node->cmd[i])
	{
		free(node->cmd[i]);
		i++;
	}
	free(node->cmd);
}

void	px_free_info(t_cmd_info *list)
{
	int	i;
	t_cmd	*to_free;

	to_free = list->head;
	while (to_free)
	{
		px_free_node(to_free);
		to_free = to_free->next;
	}
	i = 0;
	while (list->path[i])
	{
		free(list->path[i]);
		i++;
	}
	free(list->path);
}

int		main(int ac, char **av, char **envp)
{
	t_cmd_info	list;
	t_cmd		*node;
	pid_t		*pid;

	px_init_cmd_info(&list, ac, av);
	save_cmd(&list, ac, av);
	list.path = find_path(envp);
	access_check(&list);
	node = list.head;
	pid = (pid_t *)ft_calloc(sizeof(pid_t), list.size);
	if (ac == 6 && list.here_doc == 1)
		px_here_doc(node, &list, envp, pid);
	else
	{
		px_child(node, &list, envp, pid);
		close(listin_fd);
	}
	close(list.out_fd);
	px_parent(&list, pid);
	px_free_info(&list);
	return (0);
}
