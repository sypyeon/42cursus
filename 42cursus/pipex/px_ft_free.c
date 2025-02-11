/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ft_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:42:09 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/11 14:36:04 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	t_cmd	*node;
	t_cmd	*to_free;

	node = list->head;
	while (node)
	{
		to_free = node;
		px_free_node(to_free);
		node = node->next;
		free(to_free);
	}
	free(list->limiter);
	i = 0;
	while (list->path[i])
	{
		free(list->path[i]);
		i++;
	}
	free(list->path);
}

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
