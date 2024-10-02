/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:30:17 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/27 16:35:10 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	strcount;

	strcount = 0;
	while (str[strcount] != '\0')
	{
		write(1, &str[strcount], 1);
		strcount++;
	}
}
