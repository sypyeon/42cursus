/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:00:49 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/19 15:34:14 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <errno.h>

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
				break ;
			write(hd_fd[1], buf, read_len);
		}
		px_close_fd(node, list);
		close(hd_fd[0]);
		close(hd_fd[1]);
		px_free_info(list);
		exit(0);
	}
	dup2(hd_fd[0], STDIN_FILENO);
	close(hd_fd[0]);
	close(hd_fd[1]);
	waitpid(hd_pid, NULL, 0);
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
		px_free_info(list);
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
		{
			free(pid);
			px_hd_child(node, list, envp);
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
