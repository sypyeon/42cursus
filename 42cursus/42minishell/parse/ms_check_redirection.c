/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:08:35 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/24 19:26:10 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"

int	ms_is_in_redir(char *str, int index)
{
	if (str[index] == '<')
	{
		index++;
		if (str[index] != '<')
			return (INPUT);
		else if (str[index] == '<')
		{
			index++;
			if (str[index] == '<')
				return (-1);
			else
				return (HEREDOC);
		}
	}
	return (0);
}

int	ms_is_out_redir(char *str, int index)
{
	if (str[index] == '>')
	{
		index++;
		if (str[index] != '>')
			return (OUTPUT);
		if (str[index] == '>')
		{
			index++;
			if (str[index] == '>')
				return (-1);
			else
				return (APPEND);
		}
	}
	return (0);
}

int	ms_is_redir(char *str, int index)
{
	int	redir;

	redir = ms_is_in_redir(str, index);
	if (redir != 0)
		return (redir);
	redir = ms_is_out_redir(str, index);
	if (redir != 0)
		return (redir);
	return (0);
}
