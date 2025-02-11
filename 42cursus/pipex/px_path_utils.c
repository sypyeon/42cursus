/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:21:18 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/11 14:40:54 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	strcmp_find_path(const char *path, const char *str)
{
	size_t	i;

	if (!path || !str)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((path[i] != str[i]) || !path[i])
			return (0);
		i++;
	}
	return (1);
}

char	**find_path(char **envp)
{
	int		i;
	char	*path;
	char	**path_split;

	i = 0;
	while (envp[i])
	{
		if (strcmp_find_path(envp[i], "PATH="))
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	path_split = ft_split(path, ':');
	free(path);
	return (path_split);
}

void	access_check(t_cmd_info *list)
{
	int		i;
	char	*cmd;
	char	*set_path;
	t_cmd	*check;

	check = list->head;
	while (check)
	{
		i = 0;
		while (list->path[i])
		{
			set_path = ft_strjoin(list->path[i], "/");
			cmd = ft_strjoin(set_path, check->cmd[0]);
			free(set_path);
			if (access(cmd, X_OK) == 0)
			{
				free(check->cmd[0]);
				check->cmd[0] = cmd;
			}
			else
				free(cmd);
			i++;
		}
		check = check->next;
	}
}
