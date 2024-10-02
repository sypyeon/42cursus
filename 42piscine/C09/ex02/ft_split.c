/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:05:36 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/31 18:57:32 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src, int size)
{
	int		i;
	char	*cpy;

	cpy = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	ft_word_count(char *str, char *charset)
{
	int	i;
	int	charset_count;
	int	word_count;

	i = 0;
	charset_count = 0;
	while (str[i] != 0)
	{
		if (is_separator(str[i], charset) == 1)
			charset_count++;
		i++;
	}
	word_count = charset_count + 1;
	return (word_count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		start;
	int		str_index;
	char	**str_arr;

	str_index = 0;
	i = ft_word_count(str, charset);
	str_arr = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (str[str_index] != 0)
	{
		while (is_separator(str[str_index], charset) == 1)
			str_index++;
		start = str_index;
		while (is_separator(str[str_index], charset) == 0
			&& str[str_index] != 0)
			str_index++;
		if (str_index != start)
		{
			str_arr[i] = ft_strdup(&str[start], str_index - start);
			i++;
		}
	}
	str_arr[i] = 0;
	return (str_arr);
}
