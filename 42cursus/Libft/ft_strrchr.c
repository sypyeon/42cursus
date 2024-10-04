/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:19:34 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/04 16:55:35 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

char *strrchr(const char *s, int c)
{
	size_t	i;
	
	i = ft_strlen(s);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return ((char*)s + i);
	}
	return (0);
}