/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:11:33 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 23:21:27 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"

t_cmd	*ms_new_cmd(char **input)
{
	t_cmd	*new;

	new = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
	if (!new)
		return (NULL);
	new->args = input;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ms_cmd_add_back(t_ms_info *list, t_cmd *new)
{
	if (!list->head)
		list->head = new;
	else
	{
		list->tail->next = new;
		new->prev = list->tail;
	}
	list->tail = new;
}

static char	*ms_replace_quote_str(char *str, int str_len)
{
	int		i;
	int		quote;
	char	*new;

	new = (char *)malloc(sizeof(char) * str_len + 1);
	if (!new)
		return (NULL);
	quote = 0;
	i = 0;
	while (str[i + quote])
	{
		if (str[i + quote] == -1)
			quote++;
		else
		{
			new[i] = str[i + quote];
			i++;
		}
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static int	ms_strlen_without_quote(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == -1)
			quote++;
		i++;
	}
	return (i - quote);
}

char	*ms_remove_quote(char *str)
{
	int	i;
	int	quote;

	i = 0;
	while (str[i])
	{
		if (ms_is_quote(str[i]))
		{
			quote = i;
			i = ms_next_quote(str, i);
			str[quote] = -1;
			if (str[i] == '\0')
				break ;
			str[i] = -1;
		}
		i++;
	}
	str = ms_replace_quote_str(str, ms_strlen_without_quote(str));
	return (str);
}
