/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:37:02 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/22 17:30:40 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char c, va_list arg)
{
	if (c == '%')
		return (write (1, "%", 1));
	if (c == 'c')
		return (write(1, (char)va_arg(arg, int), 1));
	if (c == 'd' || c == 'i')
		return (ft_d(arg));
	if (c == 's')
		ft_s();
	if (c == 'u')
	
	if (c == 'x')

	if (c == 'X')

	if (c == 'p')
	
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	int		argc;
	int		temp;
	va_list	arg;

	va_start(arg, s);
	argc = ft_arg_count(s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if(s[i] == '%' && argc < ft_arg_count(s))
		{
			i++;
			if (s[i])
				
			temp = ft_print_arg(s[i], arg);
			if (temp == -1)
				return (-1);
			count += temp;
			argc++;
			i++;
		}
		write(1, s + i, 1);
	}
}
