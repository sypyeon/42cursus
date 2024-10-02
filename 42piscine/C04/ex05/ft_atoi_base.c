/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:40:23 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/30 01:56:15 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	is_whitespace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	base_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (is_whitespace(base[i]) == 1)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	atoi_base_result(char *str, char *base, int i)
{
	int	j;
	int	result;
	int	base_len;

	result = 0;
	base_len = ft_strlen(base);
	while (str[i] != '\0')
	{
		j = 0;
		while (j < base_len)
		{
			if (str[i] == base[j])
			{
				result = result * base_len + j;
				break ;
			}
			j++;
		}
		if (j == base_len)
			return (result);
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	negative;

	negative = 1;
	i = 0;
	while (is_whitespace(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = negative * -1;
		i++;
	}
	if (base_is_valid(base) == 0)
		return (0);
	return (atoi_base_result(str, base, i) * negative);
}
