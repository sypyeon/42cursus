/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:05:40 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/15 17:58:15 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_hexa_digit(size_t arg)
{
	int	digit;

	digit = 1;
	if (arg < 0)
	{
		digit++;
		arg *= -1;
	}
	while (arg >= 16)
	{
		arg = arg / 16;
		digit++;
	}
	return (digit);
}

int	ft_p(void *arg, char *base)
{
	size_t	digit;
	size_t	s_len;
	size_t	arg_mem;
	char	*mem_to_s;

	if (!arg)
		return (write(1, "(nil)", 5));
	arg_mem = (size_t)arg;
	digit = ft_hexa_digit(arg_mem);
	mem_to_s = (char *)malloc(sizeof(char) * digit + 1);
	if (!mem_to_s)
		return (-1);
	s_len = digit;
	mem_to_s[digit] = '\0';
	while (digit > 0)
	{
		digit--;
		mem_to_s[digit] = base[arg_mem % 16];
		arg_mem = arg_mem / 16;
	}
	write(1, "0x", 2);
	write(1, mem_to_s, s_len);
	free(mem_to_s);
	return (s_len + 2);
}
