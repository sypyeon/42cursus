/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:38:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 23:18:51 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_pipe.h"
#include "ms_parse.h"
#include "ms_env.h"

static int	ms_dollar_sign_in_heredoc(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}

static int	ms_search_env_arg(char *str, int i)
{
	if ((str[i] == '_' && str[i + 1] != '_'))
		return (i + 1);
	if (str[i] == '?')
		return (i + 1);
	if (ms_is_num(str[i]))
		return (i + 1);
	if (!ms_is_blank(str[i]))
	{
		while (str[i] && !ms_is_blank(str[i]))
		{
			if (ms_is_quote(str[i]))
				return (i);
			i++;
		}
		return (i);
	}
	return (-1);
}

static char	*ms_get_env(char *str, int start, t_hash *hash)
{
	int		i;
	char	*temp;
	char	*env;

	i = start;
	if (str[i] == '$')
	{
		i = ms_search_env_arg(str, i + 1);
		temp = ms_strdup_range(str, start + 1, i);
		if (!temp)
			return (NULL);
		env = get_path(hash, temp);
		free(temp);
		return (env);
	}
	return (NULL);
}

static char	*ms_insert_env_str(char *str, char *env, int env_i)
{
	char	*front;
	char	*back;
	char	*temp;
	char	*result;

	front = ms_strdup_range(str, 0, env_i);
	temp = ft_strjoin(front, env);
	free(front);
	env_i = ms_search_env_arg(str, env_i + 1);
	back = ms_strdup_range(str, env_i, ft_strlen(str));
	result = ft_strjoin(temp, back);
	free(temp);
	free(back);
	free(str);
	return (result);
}

char	*ms_replace_heredoc_env(char *str, t_hash *hash)
{
	int		dollar_sign;
	char	*env;

	dollar_sign = ms_dollar_sign_in_heredoc(str);
	if (dollar_sign != -1)
	{
		env = ms_get_env(str, dollar_sign, hash);
		env = ms_insert_env_str(str, env, dollar_sign);
		return (env);
	}
	return (str);
}
