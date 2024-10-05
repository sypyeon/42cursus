/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:03:03 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/05 21:56:23 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*buf;

	buf = (char *)s;
	i = 0;
	while (i < n)
	{
		if (buf[i] == c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (0);
}
