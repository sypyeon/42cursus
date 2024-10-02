/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:56:06 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/13 13:56:20 by juseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

extern void	ft_putchar(char *str);

void	first_last(int c)
{
	int	ii;

	ii = 0;
	while (ii < c)
	{
		if (ii == 0 || ii == c - 1)
		{
			ft_putchar("o ");
		}
		else
		{
			ft_putchar("- ");
		}
		ii++;
	}
}

void	mid(int c)
{
	int	ii;

	ii = 0;
	while (ii < c)
	{
		if (ii == 0 || ii == c - 1)
		{
			ft_putchar("| ");
		}
		else
		{
			ft_putchar("  ");
		}
		ii++;
	}
}

void	rush(int c, int r)
{
	int	i;

	i = 0;
	while (i < r)
	{
		if (i == 0 || i == r - 1)
		{
			first_last(c);
		}
		else
		{
			mid(c);
		}
		ft_putchar("\n");
		i++;
	}
}
