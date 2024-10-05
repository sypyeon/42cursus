/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:24:15 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/05 21:56:20 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp_dest;
	char	*temp_src;

	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			temp_dest[i] = temp_src[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}
