/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:05:50 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/02 22:18:22 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char*	set;

	set = (char*)s;
	i = 0
	while (i < n)
	{
		set[i] = c;
		i++;
	}
	return (s);
}