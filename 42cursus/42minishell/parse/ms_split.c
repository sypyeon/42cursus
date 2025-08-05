/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:41:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 21:28:01 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"

char	**ms_split_dup(char **split)
{
	int		i;
	char	**dup;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
		i++;
	dup = (char **)ft_calloc(sizeof(char *), i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (split[i])
	{
		dup[i] = ft_strdup(split[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static int	ms_split_count(char *str, char delimiter)
{
	int		i;
	int		count;

	if (!str)
		return (0);
	count = 0;
	if (str[0] && str[0] != delimiter)
		count++;
	i = 1;
	if (str[0] == '\0')
		return (count);
	while (str[i])
	{
		if (ms_is_quote(str[i]))
			i = ms_next_quote(str, i);
		if (str[i] == '\0')
			break ;
		if (str[i] == delimiter && str[i - 1] != delimiter)
			count++;
		i++;
	}
	return (count);
}

char	*ms_strdup_range(char *str, int start, int end)
{
	int		i;
	char	*dup;

	if (end - start < 1)
		return (ft_strdup(""));
	dup = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (start < end)
	{
		dup[i] = str[start];
		start++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	**ms_split_line(char **result, char *line, char delim, int s_count)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (j < s_count)
	{
		while (ms_is_blank(line[i]))
			i++;
		start = i;
		while (line[i] && line[i] != delim)
		{
			if (ms_is_quote(line[i]))
				i = ms_next_quote(line, i);
			if (line[i] == '\0')
				break ;
			i++;
		}
		result[j] = ms_strdup_range(line, start, i);
		i++;
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ms_split(char *to_split, char delimiter)
{
	int		split_count;
	char	**result;

	if (!to_split)
		return (NULL);
	split_count = ms_split_count(to_split, delimiter);
	result = (char **)malloc(sizeof(char *) * (split_count + 1));
	if (!result)
		return (NULL);
	result = ms_split_line(result, to_split, delimiter, split_count);
	return (result);
}
