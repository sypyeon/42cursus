/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:40:02 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/05 21:54:46 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_iswhitespace(unsigned char c)
{
	if ((9 <= c && c <= 13) || c == 32)
	{
		return (1);
	}
	return (0);
}

int	ft_isnum(unsigned char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	is_negaitve;
	int	num;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_negaitve *= -1;
		i++;
	}
	while (ft_isnum(nptr[i]) == 1)
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * is_negaitve);
}
