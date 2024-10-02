/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:56:04 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/02 22:18:23 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char*	set;

	set = (char*)s;
	i = 0
	while (i < n)
	{
		set[i] = '\0';
		i++;
	}
	return (s);
}