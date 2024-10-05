/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:40:02 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/05 18:02:23 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_iswhitespace(unsigned char *c)
{
	if (9 <= c && c <= 13 || c == 32)
	{
		return (1);
	}
	return (0);
}

int ft_atoi(const char *nptr)
{
	int	i;
	int	is_negaitve;
	int	num;

	is_negaitve = 1;
	i = 0;
	num = 0;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			is_negaitve *= -1;
		}
		i++;
	}
	while (nptr[i] != 0)
	{

		i++;
	}
}
