/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:05:01 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/02 22:21:38 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char*	temp_d;
	char*	temp_s;

	temp_d = (char*)dest;
	temp_s = (char*)src;
	i = 0;
	while (i < n)
	{
		temp_d[i] = temp_s[i]
		i++;
	}
}