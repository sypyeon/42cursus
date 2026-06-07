/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:39:11 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/07 01:13:25 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(void *to_free)
{
	if (to_free)
		free(to_free);
	to_free = NULL;
}

void	free_map(char **to_free)
{
	int	i;

	i = 0;
	if (!to_free)
		return ;
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
	if (!to_free)
		return ;
	while (to_free[i] != NULL)
	{
		ft_free(to_free[i]);
		i++;
	}
	ft_free(to_free);
}
