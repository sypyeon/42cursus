/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:37:37 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/03 23:02:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (s[start + i] != 0 && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_str_join(char *dest, char *src)
{
	int		i;
	int		dest_len;
	int		src_len;
	char	*join;
	
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	join = (char *)malloc(sizeof(char) * (dest_len + src_len + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (dest[i])
	{
		join[i] = dest[i];
		i++;
	}
	i = 0;
	while (src[i])
	{
		join[dest_len + i] = src[i];
		i++;
	}
	return (join);
}

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
