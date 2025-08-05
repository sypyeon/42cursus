/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:27:36 by seungsch          #+#    #+#             */
/*   Updated: 2025/05/01 17:59:25 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

int	ms_builtin_cd(t_hash *hash, char *command)
{
	int		check_cwd;
	char	*temp_pwd;

	if (command == NULL)
		check_cwd = chdir(get_path(hash, "HOME"));
	else
		check_cwd = chdir(command);
	if (check_cwd == 0)
	{
		temp_pwd = ft_strdup(get_path(hash, "PWD"));
		set_path(hash, "PWD", getcwd(NULL, 0));
		set_path(hash, "OLDPWD", temp_pwd);
		set_path(hash, MS_EXIT_CODE, ft_itoa(0));
		return (1);
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("cd: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	set_path(hash, MS_EXIT_CODE, ft_itoa(1));
	return (0);
}
