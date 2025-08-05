/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:07:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 18:50:16 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"

int	ms_strcmp(char *str, char *cmp)
{
	int	i;

	if (!str || !cmp)
		return (-1);
	i = 0;
	while (str[i] && cmp[i])
	{
		if (str[i] != cmp[i])
			return (str[i] - cmp[i]);
		i++;
	}
	return (str[i] - cmp[i]);
}

int	ms_skip_single_quote(char *str, int i)
{
	i++;
	while (str[i] && str[i] != '\'')
		i++;
	if (str[i] == '\'')
		i++;
	return (i);
}

int	ms_next_quote(char *line, int i)
{
	char	quote;

	quote = line[i];
	while (line[i])
	{
		i++;
		if (line[i] == quote || line[i] == '\0')
			break ;
	}
	return (i);
}

int	ms_check_pipe(char *input)
{
	int	i;
	int	pipe_line;

	if (!input)
		return (-1);
	i = 0;
	pipe_line = 0;
	while (input[i])
	{
		if (ms_is_quote(input[i]))
			i = ms_next_quote(input, i);
		if (input[i] == '\0')
			break ;
		if (input[i] == '|')
			pipe_line++;
		i++;
	}
	return (pipe_line);
}
