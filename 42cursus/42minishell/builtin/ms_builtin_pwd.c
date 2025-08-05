/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:36:38 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/25 17:26:37 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

void	ms_builtin_pwd(t_hash *hash)
{
	char	*curr_dir;

	curr_dir = get_path(hash, "PWD");
	if (ms_strcmp(curr_dir, "") == 0)
	{
		set_path(hash, ft_strdup("PWD"), getcwd(NULL, 0));
		curr_dir = get_path(hash, "PWD");
	}
	ft_putendl_fd(curr_dir, 1);
	set_path(hash, MS_EXIT_CODE, ft_itoa(0));
	return ;
}
