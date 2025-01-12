/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:22:58 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/10 17:21:57 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_int(char *str)
{
	int			i;
	int			minus;
	long long	num;

	minus = 0;
	if (str[0] == '-')
		minus++;
	i = 0;
	num = 0;
	while (str[i + minus])
	{
		num = (num * 10) + (str[i + minus] - '0');
		if (num - minus > 2147483647 || i > 10)
			return (0);
		else if ('0' > str[i + minus] || str[i + minus] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_valid(char **av)
{
	int		i;
	int		comp;

	i = 1;
	while (av[i])
	{
		if (!ft_is_int(av[i]))
		{
			ps_av_free(av);
			exit(ft_printf("Error (not an int) \n"));
		}
		comp = i + 1;
		while (av[comp])
		{
			if (!ft_strncmp(av[i], av[comp], 11))
			{
				ps_av_free(av);
				exit (ft_printf("Error (same numbers) \n"));
			}
			comp++;
		}
		i++;
	}
}
