/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:37:37 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/01 18:46:05 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_sub_string(char *s)
{
	int	i;
	int	str_len;
	
	while (s[i] != '/n' || s[i] != '/0')
		i++;
	return (s + i);
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
	{
		free(join);
		return (NULL);
	}
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

int main()
{
	read()
}