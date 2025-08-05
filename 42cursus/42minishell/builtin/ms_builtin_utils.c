/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:37:41 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/24 23:37:48 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

int	ms_is_lowerstring(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ms_is_lower(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ms_is_blackstring(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ms_is_blank(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
