/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ft_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:42:09 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/20 21:13:22 by sipyeon          ###   ########.fr       */
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
	int		i;
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
	i = 0;
	while (list->path[i])
	{
		free(list->path[i]);
		i++;
	}
	free(list->path);
}
