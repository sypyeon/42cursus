/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:39:11 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/26 19:14:17 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(void *to_free)
{
	if (to_free)
		free(to_free);
	to_free = NULL;
}

void	d_ptr_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		ft_free(to_free[i]);
		i++;
	}
	ft_free(to_free);
}

void	visited_free(int **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		ft_free(to_free[i]);
		i++;
	}
	ft_free(to_free);
}
