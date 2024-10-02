/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 01:49:51 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/30 20:27:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str);
int	is_whitespace(char c);
int	base_is_valid(char *base);

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

void	ft_base_to(unsigned int nbr, char *base_to, int *i, char *result)
{
	unsigned int	baselen;

	baselen = ft_strlen(base_to);
	if (nbr >= baselen)
		ft_base_to(nbr / baselen, base_to, i, result);
	result[(*i)++] = base_to[nbr % baselen];
}

char	*ft_putnbr_base(unsigned int nbr, char *base_to, int negative)
{
	int		i;
	int		base_len;
	char	*result;

	i = 0;
	result = (char *)malloc(sizeof(char) * 35);
	if (result == NULL)
		return (NULL);
	base_len = ft_strlen(base_to);
	if (base_is_valid(base_to) == 0)
		return (NULL);
	if (negative < 0)
	{
		result[i] = '-';
		i++;
	}
	ft_base_to(nbr, base_to, &i, result);
	result[i] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				atoi_num;
	unsigned int	num;

	if (base_is_valid(base_to) == 0 || base_is_valid(base_from) == 0)
		return (0);
	atoi_num = ft_atoi_base(nbr, base_from);
	if (atoi_num < 0)
		num = atoi_num * -1;
	else
		num = atoi_num;
	return (ft_putnbr_base(num, base_to, atoi_num));
}
