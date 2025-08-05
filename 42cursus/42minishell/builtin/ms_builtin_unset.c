/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:15 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/25 17:26:41 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

void	ms_builtin_unset(t_hash *hash, char **key)
{
	int	i;

	i = 1;
	while (key[i] != NULL)
	{
		del_path(hash, key[i]);
		i++;
	}
	set_path(hash, MS_EXIT_CODE, ft_itoa(0));
	return ;
}
