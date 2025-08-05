/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:23:22 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/27 23:53:54 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_pipe.h"

static void	first_node_setting(t_cmd *cmd)
{
	if (cmd->here_doc == 1)
		dup2(cmd->hd_pipe_fd[0], STDIN_FILENO);
	else if (cmd->in_fd != 0)
		dup2(cmd->in_fd, STDIN_FILENO);
	if (cmd->out_fd != 0)
		dup2(cmd->out_fd, STDOUT_FILENO);
	else if (cmd->next != NULL)
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
}

static void	last_node_setting(t_cmd *cmd)
{
	if (cmd->in_fd != 0)
		dup2(cmd->in_fd, STDIN_FILENO);
	else if (cmd->here_doc == 1)
		dup2(cmd->hd_pipe_fd[0], STDIN_FILENO);
	else
		dup2(cmd->prev->pipe_fd[0], STDIN_FILENO);
	if (cmd->out_fd)
		dup2(cmd->out_fd, STDOUT_FILENO);
}

static void	middle_node_setting(t_cmd *cmd)
{
	if (cmd->here_doc == 1)
		dup2(cmd->hd_pipe_fd[0], STDIN_FILENO);
	else if (cmd->in_fd)
		dup2(cmd->in_fd, STDIN_FILENO);
	else
		dup2(cmd->prev->pipe_fd[0], STDIN_FILENO);
	if (cmd->out_fd)
		dup2(cmd->out_fd, STDOUT_FILENO);
	else
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
}

void	dup_setting(t_cmd *cmd)
{
	if (cmd->prev == NULL)
	{
		first_node_setting(cmd);
	}
	else if (cmd->next == NULL)
		last_node_setting(cmd);
	else
		middle_node_setting(cmd);
}
