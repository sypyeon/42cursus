/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:23:01 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/22 00:12:47 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_hex(int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex[num / 16], 1);
	write(1, &hex[num % 16], 1);
}

int	char_is_printable(char c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	strcount;

	strcount = 0;
	while (str[strcount] != '\0')
	{
		if (char_is_printable(str[strcount]) == 1)
			write(1, &str[strcount], 1);
		else
			ft_hex(str[strcount]);
		strcount++;
	}
}
