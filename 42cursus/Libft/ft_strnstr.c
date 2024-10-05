/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:52:16 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/05 21:06:43 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	cmp;

	i = 0;
	if (*little == 0)
		return (big);
	while (big[i] != 0 && i < len)
	{
		cmp = 0;
		if (big[i] == little[cmp])
		{
			while (little[cmp] != 0)
			{
				if (big[i + cmp] != little[cmp])
					break ;
				cmp++;
			}
			return (big[i]);
		}
		i++;
	}
	return (0);
}
