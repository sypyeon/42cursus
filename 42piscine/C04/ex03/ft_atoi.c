/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:10:51 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/27 13:39:12 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	strcount;
	int	negative;
	int	num;

	strcount = 0;
	negative = 1;
	num = 0;
	while (is_whitespace(str[strcount]) == 1)
		strcount++;
	while (str[strcount] == '-' || str[strcount] == '+')
	{
		if (str[strcount] == '-')
			negative = negative * -1;
		strcount++;
	}
	while ('0' <= str[strcount] && str[strcount] <= '9')
	{
		num = (num * 10) + (str[strcount] - '0');
		strcount++;
	}
	num = num * negative;
	return (num);
}
