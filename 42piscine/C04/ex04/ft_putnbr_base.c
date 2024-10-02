/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:27:28 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/30 01:59:40 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen] != '\0')
		strlen++;
	return (strlen);
}

int	base_is_valid(char *base)
{
	int	strcount;
	int	strcmp;

	strcount = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[strcount] != '\0')
	{
		if (base[strcount] == '-' || base[strcount] == '+')
			return (0);
		strcmp = strcount + 1;
		while (base[strcmp] != '\0')
		{
			if (base[strcount] == base[strcmp])
				return (0);
			strcmp++;
		}
		strcount++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		baselen;
	long	largenbr;

	baselen = ft_strlen(base);
	largenbr = nbr;
	if (base_is_valid(base) == 0)
		return ;
	if (largenbr < 0)
	{
		write(1, "-", 1);
		largenbr = largenbr * -1;
	}
	if (largenbr >= baselen)
		ft_putnbr_base(largenbr / baselen, base);
	write(1, &base[largenbr % baselen], 1);
}
