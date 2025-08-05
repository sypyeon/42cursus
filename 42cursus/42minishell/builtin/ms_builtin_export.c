/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:17 by seungsch          #+#    #+#             */
/*   Updated: 2025/05/01 18:23:52 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

static void	ms_export_declare(t_hash *hash)
{
	int	i;
	char **env;

	i = 0;
	env = change_hash(*hash);
	while (env[i])
	{
		if (ft_strncmp(env[i], "?=", 2) == 0||ft_strncmp(env[i], "0=", 2) == 0)
		{
			i++;
			continue ;
		}
		ft_printf("declare -x ");
		ft_putendl_fd(env[i], 1);
		i++;
	}
	ms_free_split(env);
	return ;
}

static int		check_valied_path(char *path)
{
	char	**parse_path;

	parse_path = ft_split(path, '=');
	if (ms_is_num(parse_path[0][0]) == 0)
	{
		if (ms_is_blackstring(parse_path[0]) == 0)
		{
			return (1);
		}
	}
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": not a valied identifier", 2);
	return (0);
}

void	ms_builtin_export(t_hash *hash, char **path)
{
	int		i;
	int		flag;
	i = 1;
	flag = 0;
	
	if (path[i] == NULL)
	{
		ms_export_declare(hash);
		return ;
	}
	while (path[i] != NULL)
	{
		if (check_valied_path(path[i]) && \
		ms_strcmp(get_path(hash, path[i]), "") == 0)
		{
			add_path(hash, path[i]);
			set_path(hash, MS_EXIT_CODE, ft_itoa(0));
		}
		else
			flag = 1;
		i++;
	}
	if (flag == 1)
		set_path(hash, MS_EXIT_CODE, ft_itoa(1));	
	return ;
}
