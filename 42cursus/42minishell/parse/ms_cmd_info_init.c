/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_info_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:41:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 23:22:06 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_env.h"
#include "ms_parse.h"

t_cmd	*ms_new_cmd(char **input);
void	ms_cmd_add_back(t_ms_info *list, t_cmd *new);

char	*ms_convert_tab_to_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ms_is_quote(str[i]))
			i = ms_next_quote(str, i);
		if (str[i] == '\0')
			return (str);
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (str);
}

void	ms_find_quote_and_remove(t_cmd *cmd)
{
	int		i;
	char	*str;

	if (!cmd)
		return ;
	if (!cmd->x_cmd)
		return ;
	i = 0;
	while (cmd->x_cmd[i])
	{
		str = cmd->x_cmd[i];
		cmd->x_cmd[i] = ms_remove_quote(str);
		i++;
	}
}

void	ms_cmd_init(char *cmd_arg, t_hash *hash, t_ms_info *info)
{
	t_cmd	*cmd;
	char	*temp;
	char	*trimed;

	cmd = ms_new_cmd(ms_split(cmd_arg, ' '));
	temp = ms_redir_check(cmd_arg, cmd);
	ms_apply_redirection(cmd, hash);
	trimed = ft_strtrim(temp, " \t");
	cmd->x_cmd = ms_split(trimed, ' ');
	ms_set_env_val(cmd, hash);
	ms_find_quote_and_remove(cmd);
	free(temp);
	free(trimed);
	ms_cmd_add_back(info, cmd);
}

void	ms_cmd_info_init(t_ms_info *info, char *input, t_hash *hash)
{
	int		i;

	input = ms_convert_tab_to_space(input);
	info->path = ft_split(get_path(hash, "PATH"), ':');
	info->size = ms_check_pipe(input) + 1;
	info->args = ms_split(input, '|');
	free(input);
	if (!info->args)
		return ;
	i = 0;
	while (info->args[i])
	{
		ms_cmd_init(info->args[i], hash, info);
		i++;
	}
	ms_free_split(info->args);
}
