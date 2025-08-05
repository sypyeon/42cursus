/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_identify_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:23:23 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/27 18:28:34 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"

int	ms_is_lower(int c)
{
	return ('a' <= c && c <= 'z');
}

int	ms_is_upper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ms_is_num(int c)
{
	return ('0' <= c && c <= '9');
}

int	ms_is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	ms_find_dollar_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = ms_skip_single_quote(str, i);
		else if (str[i] == '\"')
		{
			while (str[i])
			{
				i++;
				if (str[i] == '$')
					return (i);
				if (str[i] == '\"')
					break ;
			}
		}
		if (!str[i])
			break ;
		if (str[i] == '$' && (!ms_is_blank(str[i + 1]) || str[i + 1]))
			return (i);
		i++;
	}
	return (-1);
}
