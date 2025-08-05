/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:43:42 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 18:33:38 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_struct.h"
#include "ms_free.h"

void	ms_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	ms_free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->x_cmd)
		ms_free_split(cmd->x_cmd);
	if (cmd->args)
		ms_free_split(cmd->args);
	if (cmd->redir_info)
		ms_free_split(cmd->redir_info);
}

void	ms_close_fd(t_cmd *cmd)
{
	if (cmd->pipe_fd[0] > 0)
		close(cmd->pipe_fd[0]);
	if (cmd->pipe_fd[1] > 0)
		close(cmd->pipe_fd[1]);
	if (cmd->in_fd > 0)
		close(cmd->in_fd);
	if (cmd->out_fd > 0)
		close(cmd->out_fd);
}

void	ms_free_info(t_ms_info *info)
{
	t_cmd	*cmd;
	t_cmd	*to_free;

	cmd = info->head;
	if (cmd == NULL)
	{
		ms_free_split(info->path);
		return ;
	}
	while (cmd)
	{
		to_free = cmd;
		cmd = cmd->next;
		ms_free_cmd(to_free);
		free(to_free);
	}
	ms_free_split(info->path);
}
