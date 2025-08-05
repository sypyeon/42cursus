/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_apply_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:55:21 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/28 23:17:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"
#include <stdio.h>

void	ms_heredoc_process(t_cmd *cmd, t_hash *hash);

static void	ms_open_in_fd(char *file_name, t_cmd *cmd, int redir, t_hash *hash)
{
	if (cmd->in_fd == -1)
		return ;
	else if (cmd->in_fd != 0)
	{
		close(cmd->in_fd);
		cmd->in_fd = 0;
	}
	if (redir == INPUT)
	{
		cmd->in_fd = open(file_name, O_RDONLY);
		if (cmd->in_fd == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(file_name);
		}
	}
	else if (redir == HEREDOC)
	{
		cmd->here_doc = 1;
		cmd->limiter = file_name;
		ms_heredoc_process(cmd, hash);
	}
}

static void	ms_open_out_fd(char *file_name, t_cmd *cmd, int redir)
{
	if (cmd->out_fd == -1)
		return ;
	else if (cmd->out_fd != 0)
	{
		close(cmd->out_fd);
		cmd->out_fd = 0;
	}
	if (redir == OUTPUT)
		cmd->out_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir == APPEND)
		cmd->out_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->out_fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(file_name);
	}
}

char	*ms_heredoc_quote_check(t_cmd *cmd, char *file_name, int redir)
{
	int	i;

	i = 0;
	while (file_name[i])
	{
		if (ms_is_quote(file_name[i]) && redir == HEREDOC)
			cmd->eof_quote = 1;
		i++;
	}
	file_name = ms_remove_quote(file_name);
	return (file_name);
}

void	ms_apply_redirection(t_cmd *cmd, t_hash *hash)
{
	int		i;
	int		redir;
	char	*file_name;

	i = 0;
	if (!cmd->redir_info)
		return ;
	while (cmd->redir_info[i])
	{
		redir = ms_is_redir(cmd->redir_info[i], 0);
		file_name = ft_strtrim(cmd->redir_info[i], " <>");
		file_name = ms_heredoc_quote_check(cmd, file_name, redir);
		if (redir == INPUT || redir == HEREDOC)
			ms_open_in_fd(file_name, cmd, redir, hash);
		else if (redir == OUTPUT || redir == APPEND)
			ms_open_out_fd(file_name, cmd, redir);
		free(file_name);
		i++;
	}
}
