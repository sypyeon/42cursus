/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:55:58 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/25 17:26:26 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

void	ms_builtin_env(t_hash *hash)
{
	char	**parse_env;
	int		i;

	i = 0;
	parse_env = change_hash(*hash);
	while (parse_env[i] != NULL)
	{
		if (ft_strncmp(parse_env[i], "?=", 2) == 0)
		{
			i++;
			continue ;
		}
		else if (ft_strncmp(parse_env[i], "0=", 2) == 0)
		{
			i++;
			continue ;
		}
		ft_putendl_fd(parse_env[i], 1);
		i++;
	}
	set_path(hash, MS_EXIT_CODE, ft_itoa(0));
	free_split(parse_env);
	return ;
}
