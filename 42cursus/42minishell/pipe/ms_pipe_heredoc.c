/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:42:45 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/28 23:19:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_pipe.h"
#include "ms_hash.h"

static void	ms_hd_pipe_close(t_cmd *cmd)
{
	if (cmd->hd_pipe_fd[0] != 0)
	{
		close (cmd->hd_pipe_fd[0]);
		close (cmd->hd_pipe_fd[1]);
	}
}

static void	hd_pipe_close(char *heredoc_input, t_cmd *cmd)
{
	if (heredoc_input == NULL || g_ms_signum == SIGINT)
	{
		ms_hd_pipe_close(cmd);
		cmd->here_doc = -2;
	}
	if (ms_strcmp(heredoc_input, cmd->limiter) == 0)
		close(cmd->hd_pipe_fd[1]);
}

static int	ms_heredoc_eof(char *heredoc_input, t_cmd *cmd)
{
	if (ms_strcmp(heredoc_input, cmd->limiter) == 0)
		return (1);
	if (heredoc_input == NULL || g_ms_signum == SIGINT)
		return (1);
	return (0);
}

static void	ms_heredoc_loop(t_cmd *cmd, t_hash *hash)
{
	char	*heredoc_input;

	while (1)
	{
		heredoc_input = readline("> ");
		if (ms_heredoc_eof(heredoc_input, cmd))
		{
			hd_pipe_close(heredoc_input, cmd);
			return ;
		}
		if (cmd->eof_quote == 0)
			heredoc_input = ms_replace_heredoc_env(heredoc_input, hash);
		write(cmd->hd_pipe_fd[1], heredoc_input, ft_strlen(heredoc_input));
		write(cmd->hd_pipe_fd[1], "\n", 1);
		free(heredoc_input);
	}
}

void	ms_heredoc_process(t_cmd *cmd, t_hash *hash)
{
	int		in_dup;

	in_dup = dup(STDIN_FILENO);
	heredoc_signal();
	ms_hd_pipe_close(cmd);
	pipe(cmd->hd_pipe_fd);
	ms_heredoc_loop(cmd, hash);
	dup2(in_dup, STDIN_FILENO);
	close(in_dup);
	if (g_ms_signum == 0)
		set_path(hash, "?", ft_itoa(g_ms_signum));
	else
		set_path(hash, "?", ft_itoa(128 + g_ms_signum));
	g_ms_signum = 0;
	signal_lock();
}
