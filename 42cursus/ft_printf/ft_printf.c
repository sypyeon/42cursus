/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:37:02 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/21 01:21:13 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_arg(char c, void *arg)
{
	if (c == 'd')
		ft_d(c);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	argc;
	va_list	arg;

	va_start(arg, s);
	argc = 0;
	i = 0;
	while (s[i])
	{
		if(s[i] == '%' && argc <= ft_arg_count(s))
		{
			i++;
			if (s[i] == '%')
				ft_print_arg(s[i], va_arg(arg, void *));
			argc++;
			i++;
		}
		write(1, s + i, 1);
	}
}
