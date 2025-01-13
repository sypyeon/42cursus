/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:19:14 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/17 16:10:34 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*dup;

	i = 0;
	s_len = 0;
	while (s[s_len] != 0)
		s_len++;
	dup = (char *)malloc(sizeof(char) * s_len + 1);
	if (!(dup))
		return (0);
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}
