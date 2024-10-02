/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:47:07 by hocho             #+#    #+#             */
/*   Updated: 2024/08/14 21:06:34 by juseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char *c);

void	ft_first(int c)
{
	int	ii;

	ii = 0;
	while (ii < c)
	{			
		if (ii == 0)
		{
			ft_putchar("A");
		}
		else if (ii < c - 1)
		{
			ft_putchar("B");
		}
		else if (ii == c - 1)
		{
			ft_putchar("C");
		}
		ii++;
	}
}

void	ft_middle(int c)
{
	int	ii;

	ii = 0;
	while (ii < c)
	{			
		if (ii == 0)
		{
			ft_putchar("B");
		}
		else if (ii < c - 1)
		{
			ft_putchar(" ");
		}
		else if (ii == c - 1)
		{
			ft_putchar("B");
		}
		ii++;
	}
}

void	ft_last(int c)
{
	int	ii;

	ii = 0;
	while (ii < c)
	{			
		if (ii == 0)
		{
			ft_putchar("A");
		}
		else if (ii < c - 1)
		{
			ft_putchar("B");
		}
		else if (ii == c -1)
		{
			ft_putchar("C");
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
		if (i == 0)
		{
			ft_first(c);
			ft_putchar("\n");
		}
		else if (i < r - 1)
		{
			ft_middle(c);
			ft_putchar("\n");
		}
		else
		{
			ft_last(c);
			ft_putchar("\n");
		}
		i++;
	}
}
