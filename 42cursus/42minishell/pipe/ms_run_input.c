/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:00:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 23:19:30 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_check(t_cmd	*cmd, t_hash *hash, int flag, t_ms_info *info)
{
	if (flag == 1)
		return (0);
	if (ms_strcmp(cmd->x_cmd[0], "cd") == 0)
		ms_builtin_cd(hash, cmd->x_cmd[1]);
	else if (ms_strcmp(cmd->x_cmd[0], "env") == 0)
		ms_builtin_env(hash);
	else if (ms_strcmp(cmd->x_cmd[0], "pwd") == 0)
		ms_builtin_pwd(hash);
	else if (ms_strcmp(cmd->x_cmd[0], "export") == 0)
		ms_builtin_export(hash, cmd->x_cmd);
	else if (ms_strcmp(cmd->x_cmd[0], "unset") == 0)
		ms_builtin_unset(hash, cmd->x_cmd);
	else if (ms_strcmp(cmd->x_cmd[0], "echo") == 0)
		ms_builtin_echo(hash, cmd);
	else if (ms_strcmp(cmd->x_cmd[0], "exit") == 0)
		ms_builtin_exit(hash, info);
	else
		return (0);
	return (1);
}

static void	cmd_not_found(t_cmd *cmd, t_ms_info *info, t_hash *hash)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(cmd->x_cmd[0], 2);
	ms_free_info(info);
	free_hash(hash);
	exit(127);
}

void	access_check(t_cmd *cmd, t_ms_info *info, t_hash *hash)
{
	int		path_idx;
	char	*command;
	char	*temp;

	if (cmd->x_cmd[0][0] == '\0')
		return ;
	path_idx = 0;
	if (cmd->x_cmd[0][0] == '/' && access(cmd->x_cmd[0], X_OK) == 0)
		return ;
	while (info->path[path_idx] && cmd->x_cmd[0][0] != '/')
	{
		temp = ft_strjoin("/", cmd->x_cmd[0]);
		command = ft_strjoin(info->path[path_idx], temp);
		free(temp);
		if (access(command, X_OK) == 0)
		{
			free(cmd->x_cmd[0]);
			cmd->x_cmd[0] = command;
			return ;
		}
		else
			free(command);
		path_idx++;
	}
	cmd_not_found(cmd, info, hash);
}

int	ms_check_syntax_error(t_cmd *cmd)
{
	if (cmd == NULL)
		return (SYNTAX_ERR);
	while (cmd != NULL)
	{
		if (cmd->x_cmd[0] == NULL)
		{
			if (cmd->hd_pipe_fd[0])
				close(cmd->hd_pipe_fd[0]);
		}
		if (cmd->here_doc == -2)
			return (HEREDOC_SIG);
		cmd = cmd->next;
	}
	return (0);
}

void	ms_run_input(t_ms_info *info, t_hash *hash)
{
	int	builtin_flag;
	int	error;

	error = ms_check_syntax_error(info->head);
	if (error == SYNTAX_ERR)
	{
		write(2, "minishell: syntax error\n", 25);
		set_path(hash, "?", ft_strdup("2"));
		return ;
	}
	if (error == HEREDOC_SIG)
		return ;
	if (info->head->next != NULL)
		builtin_flag = builtin_check(info->head, hash, 1, info);
	else
		builtin_flag = builtin_check(info->head, hash, 0, info);
	if (builtin_flag == 0)
		main_pipe(info, hash);
}
