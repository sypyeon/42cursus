/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:26:19 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/25 16:33:53 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

static int	args_num_check(t_cmd *cmd)
{
	if (cmd == NULL)
		return (0);
	if (cmd->x_cmd[0] && cmd->x_cmd[1] && cmd->x_cmd[2] == NULL)
		return (1);
	return (0);
}

void	ms_builtin_exit(t_hash *hash, t_ms_info *info)
{
	int	exit_code;
	int	flag;

	flag = 0;
	exit_code = 0;
	if (args_num_check(info->head) == 1)
	{
		if (ms_is_lowerstring(info->head->x_cmd[1]) == 0)
			exit_code = ft_atoi(info->head->x_cmd[1]);
		else
			flag = 1;
	}
	else
		flag = 1;
	if (flag == 1)
		exit_code = ft_atoi(get_path(hash, MS_EXIT_CODE));
	free_hash(hash);
	ms_free_info(info);
	ft_putendl_fd("exit", 1);
	exit(exit_code);
}
