/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:34:20 by seungsch          #+#    #+#             */
/*   Updated: 2025/05/01 18:00:11 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_pipe.h"

static void	process(t_cmd *cmd, t_hash *hash, int flag, t_ms_info *info)
{
	char	**argv;
	char	**envp;

	argv = ms_split_dup(cmd->x_cmd);
	envp = change_hash(*hash);
	ms_free_info(info);
	free_hash(hash);
	(void)flag;
	if (execve(argv[0], argv, envp) == -1)
		process_exitcode_setting(argv, envp);
}

static void	parent_process(t_cmd *cmd)
{
	if (cmd->prev != NULL)
	{
		close(cmd->prev->pipe_fd[0]);
		close(cmd->prev->pipe_fd[1]);
	}
	if (cmd->hd_pipe_fd[0] != 0)
		close(cmd->hd_pipe_fd[0]);
}

static void	child_process(t_ms_info *info, t_hash *hash, t_cmd *cmd)
{
	int	builtin_flag;

	builtin_flag = 0;
	signal_unlock();
	if (cmd->in_fd == -1 || cmd->out_fd == -1)
	{
		pipe_close(info->head);
		ms_free_info(info);
		free_hash(hash);
		exit(1);
	}
	dup_setting(cmd);
	pipe_close(info->head);
	builtin_flag = builtin_check(cmd, hash, 0, info);
	if (builtin_flag == 0)
	{
		if (cmd->x_cmd[0] != NULL)
		{
			access_check(cmd, info, hash);
			process(cmd, hash, builtin_flag, info);
		}
	}
	ms_free_info(info);
	free_hash(hash);
	exit(0);
}

static void	pipe_process(t_ms_info *info, t_hash *hash)
{
	t_cmd	*cmd;
	int		builtin_flag;

	builtin_flag = 0;
	cmd = info->head;
	while (cmd != NULL)
	{
		pipe(cmd->pipe_fd);
		cmd->pid = fork();
		if (cmd->pid == 0)
			child_process(info, hash, cmd);
		else
			parent_process(cmd);
		cmd = cmd->next;
	}
	pipe_close(info->head);
}

void	main_pipe(t_ms_info *info, t_hash *hash)
{
	t_cmd	*cmd;
	int		status;

	status = 0;
	pipe_process(info, hash);
	cmd = info->head;
	while (cmd != NULL)
	{
		waitpid(cmd->pid, &status, 0);
		cmd = cmd->next;
	}
	sigint_exitcode_setting(hash, status);
}
