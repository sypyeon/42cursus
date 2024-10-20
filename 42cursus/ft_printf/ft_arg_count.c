/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:52 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/20 18:05:41 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_count(const char *s)
{
	int	i;
	int	arg_count;

	arg_count = 0;
	i = 0;
	while (s[i])
	{
		if(s[i] == '%' && s[i + 1] != '%')
			arg_count++;
		i++;
	}
	return (arg_count);
}