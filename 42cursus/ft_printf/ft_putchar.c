/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:15:05 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/22 13:15:36 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(long c)
{
	c = (unsigned char)c;
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

// int	main()
// {
// 	ft_putchar('');
// 	return 0;
// }