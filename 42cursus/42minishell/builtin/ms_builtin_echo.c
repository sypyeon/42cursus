/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:39:27 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/28 18:00:30 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

void	ms_builtin_echo(t_hash *hash, t_cmd *cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (ms_strcmp(cmd->x_cmd[1], "-n") == 0)
	{
		flag = 1;
		i++;
	}
	if (cmd->out_fd > 0)
		flag = 1;
	while (cmd->x_cmd[i])
	{
		ft_putstr_fd(cmd->x_cmd[i], cmd->out_fd);
		if (cmd->x_cmd[i + 1] != NULL)
			ft_putstr_fd(" ", cmd->out_fd);
		i++;
	}
	if (flag == 0)
		ft_printf("\n");
	ms_close_fd(cmd);
	set_path(hash, MS_EXIT_CODE, ft_itoa(0));
	return ;
}
