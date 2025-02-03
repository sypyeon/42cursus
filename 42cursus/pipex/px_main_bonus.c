/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:37:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/04 01:43:17 by sipyeon          ###   ########.fr       */
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
	// free_func;
}

void	px_child_fd_dup(t_cmd *node, t_cmd_info *list)
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
}

void	px_child(t_cmd *node, t_cmd_info *list, char **envp)
{
	
	px_child_fd_dup(node, list);
	if (execve(node->cmd[0], node->cmd, envp) == -1)
	{
		perror(node->cmd[0]);
		// freefunc;
		exit(errno);
	}
}

void	px_make_child_to_execve(t_cmd *node, t_cmd_info *list, char **envp)
{
	int		i;
	pid_t	*pid;

	pid = (pid_t *)malloc(sizeof(pid_t) * list->size);
	i = 0;
	while (node)
	{
		if (node->next)
			pipe(node->fd);
		pid[i] = fork();
		if (pid[i] == 0)
			px_child(node, list, envp);
		if (node->prev)
		{
			close(node->prev->fd[0]);
			close(node->prev->fd[1]);
		}
		node = node->next;
		i++;
	}
}

void	px_here_doc(t_cmd *node, t_cmd_info *list, char **envp)
{
	
}

int		main(int ac, char **av, char **envp)
{
	t_cmd_info	list;
	t_cmd		*node;
	pid_t		*pid;

	px_init_cmd_info(&list, ac, av);
	save_cmd(&list, av);
	list.path = find_path(envp);
	access_check(&list);
	node = list.head;
	if (ac = 6 && av[1] == "here_doc")
		px_here_doc(node, &list, envp);
	else
		px_make_child_to_execve(node, &list, envp);
	close(list.in_fd);
	close(list.out_fd);
	px_parent(&list, pid);
	return (0);
}
