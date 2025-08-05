/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:37:19 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/28 17:28:17 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_pipe.h"

void	sigint_exitcode_setting(t_hash *hash, int status)
{
	char	*code;

	code = NULL;
	if (WIFEXITED(status))
	{
		code = ft_itoa(WEXITSTATUS(status));
		set_path(hash, MS_EXIT_CODE, code);
	}
	else if (WIFSIGNALED(status))
	{
		code = ft_itoa(128 + WTERMSIG(status));
		write(STDOUT_FILENO, "\n", 1);
		set_path(hash, MS_EXIT_CODE, code);
	}
}

void	process_exitcode_setting(char **argv, char **envp)
{
	perror(argv[0]);
	ms_free_split(argv);
	ms_free_split(envp);
	if (errno == 13)
		exit(126);
	exit(1);
}

void	pipe_close(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	while (cmd != NULL)
	{
		if (cmd->in_fd > 0)
			close(cmd->in_fd);
		if (cmd->out_fd > 0)
			close(cmd->out_fd);
		if (cmd->pipe_fd[0] > 0)
		{
			close(cmd->pipe_fd[0]);
			close(cmd->pipe_fd[1]);
		}
		if (cmd->hd_pipe_fd[0] > 0)
		{
			close(cmd->hd_pipe_fd[0]);
			close(cmd->hd_pipe_fd[1]);
		}
		cmd = cmd->next;
	}
}
