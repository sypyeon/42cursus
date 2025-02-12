/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:37:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/12 18:42:50 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "pipex.h"

void	px_parent(t_cmd_info *list, pid_t *pid)
{
	int	i = 0;

	while (i < list->size)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
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
		px_free_info(list);
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
		{
			free(pid);
			px_child_execve(node, list, envp);
		}
		if (node->prev)
		{
			close(node->prev->fd[0]);
			close(node->prev->fd[1]);
		}
		node = node->next;
		i++;
	}
}

int		main(int ac, char **av, char **envp)
{
	t_cmd_info	list;
	t_cmd		*node;
	pid_t		*pid;

	printf("%d", ac);
	if (ac < 4)
		return (write(2, "Not enough arguments", 21));
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
		close(list.in_fd);
	}
	close(list.out_fd);
	px_parent(&list, pid);
	px_free_info(&list);
	free(pid);
	return (0);
}
