/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:30:29 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/08 23:32:31 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(int a, int b, int c)
{
	char	ca;
	char	cb;
	char	cc;

	ca = a + '0';
	cb = b + '0';
	cc = c + '0';
	write(1, &ca, 1);
	write(1, &cb, 1);
	write(1, &cc, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				ft_putchar(a, b, c);
				if (a + b + c < 24)
				{
					write(1, ", ", 2);
				}
				c++;
			}
			b++;
		}
		a++;
	}	
}

int main()
{
	ft_print_comb();
	return 0;
}