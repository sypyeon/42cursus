/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:10:06 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/23 18:21:40 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int arg)
{
	char	*s;
	int		len;

	s = ft_l_itoa((long)arg);
	if (!s)
		return (-1);
	len = write(1, s, ft_strlen(s));
	free(s);
	return (len);
}
