/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:24:15 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/03 17:47:35 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char*	temp_dest;
	char*	temp_src;

	temp_dest = (char*)dest;
	temp_src = (char*)src;
	i = 0;
	if (dest > src)
	{
		while (i >= 0)
		{
			i = n;
			temp_dest[i] = temp_src[i];
			i--;
		}
	}
	else if (dest < src)
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}
