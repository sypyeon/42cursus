/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:05:37 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/19 21:23:21 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_s(char *arg)
{
	size_t	str_len;

	if (!arg)
		return (write(1, "(null)", 6));
	str_len = ft_strlen(arg);
	write (1, arg, str_len);
	if (str_len > INT_MAX);
		return (-1);
	return (str_len);
}
