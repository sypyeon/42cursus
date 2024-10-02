/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:51:09 by sipyeon           #+#    #+#             */
/*   Updated: 2024/09/01 01:16:16 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_join_len(int size, char **strs, char *sep)
{
	int	i;
	int	join_len;
	int	sep_len;

	i = 0;
	join_len = 0;
	while (i < size)
	{
		join_len = join_len + ft_strlen(strs[i]);
		i++;
	}
	sep_len = ft_strlen(sep);
	join_len += (size - 1) * sep_len;
	return (join_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;
	int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	while (i < src_len)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		str_len;
	char	*str_join;

	if (size <= 0)
	{
		str_join = (char *)malloc(sizeof(char));
		*str_join = 0;
		return (str_join);
	}
	str_len = ft_join_len(size, strs, sep);
	str_join = (char *)malloc((str_len + 1) * (sizeof(char)));
	if (str_join == 0)
		return (NULL);
	i = 0;
	*str_join = '\0';
	while (i < size)
	{
		ft_strcat(str_join, strs[i]);
		if (i < (size - 1))
			ft_strcat(str_join, sep);
		i++;
	}
	return (str_join);
}
