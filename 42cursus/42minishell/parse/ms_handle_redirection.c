/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:01:48 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 18:53:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"

int	ms_valid_redir(char *str)
{
	int	i;
	int	redir;
	int	redir_count;

	if (!str)
		return (-1);
	i = 0;
	redir_count = 0;
	while (str[i])
	{
		if (ms_is_quote(str[i]))
			i = ms_next_quote(str, i);
		if (str[i] == '\0')
			break ;
		redir = ms_is_redir(str, i);
		if (redir == -1)
			return (-1);
		if (redir != 0)
			redir_count++;
		if (redir == APPEND || redir == HEREDOC)
			i++;
		i++;
	}
	return (redir_count);
}

int	ms_find_redir_arg(char *str, int i)
{
	if (!str)
		return (0);
	if (str[i] == '<' || str[i] == '>')
		i++;
	while (ms_is_blank(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '<' || str[i] == '>')
		return (0);
	while (str[i])
	{
		if (ms_is_quote(str[i]))
			i = ms_next_quote(str, i);
		if (ms_is_blank(str[i]))
			break ;
		i++;
	}
	return (i);
}

char	*ms_remove_redir(char *arg, int trim_idx)
{
	int		i;
	char	*result;
	char	*front;
	char	*back;

	i = 0;
	while (arg[i] && arg[i] != '<' && arg[i] != '>')
		i++;
	front = ms_strdup_range(arg, 0, i);
	back = ms_strdup_range(arg, trim_idx, ft_strlen(arg));
	result = ft_strjoin(front, back);
	free(front);
	free(back);
	free(arg);
	return (result);
}

int	ms_find_redir_idx(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '<' || arg[i] == '>')
			break ;
		i++;
	}
	return (i);
}

char	*ms_redir_check(char *arg, t_cmd *cmd)
{
	int		i;
	int		redir_idx;
	int		trim_end;
	char	*new_arg;

	cmd->redir = ms_valid_redir(arg);
	cmd->redir_info = (char **)ft_calloc(cmd->redir + 1, sizeof(char *));
	if (!arg)
	{
		cmd->redir_info = NULL;
		return (NULL);
	}
	new_arg = ft_strdup(arg);
	i = 0;
	while (i < cmd->redir)
	{
		redir_idx = ms_find_redir_idx(new_arg);
		trim_end = ms_find_redir_arg(new_arg, redir_idx + 1);
		cmd->redir_info[i] = ms_strdup_range(new_arg, redir_idx, trim_end);
		new_arg = ms_remove_redir(new_arg, trim_end);
		i++;
	}
	cmd->redir_info[i] = NULL;
	return (new_arg);
}
