/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:06:22 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/22 13:41:41 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else
		return (0);
}

int	is_uppercase(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}

int	alphanum(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else if (is_lowercase(c) == 1)
		return (1);
	else if (is_uppercase(c) == 1)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	strcount;
	int	onebehind;

	strcount = 0;
	while (str[strcount] != '\0')
	{
		onebehind = strcount - 1;
		if (is_lowercase(str[strcount]) == 1)
			str[strcount] = str[strcount] - 32;
		if (is_uppercase(str[strcount]) == 1
			&& alphanum(str[onebehind]) == 1)
			str[strcount] = str[strcount] + 32;
		strcount++;
	}
	return (*&str);
}
