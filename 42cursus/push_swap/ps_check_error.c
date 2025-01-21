/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:22:58 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/21 21:46:53 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_int(char *str)
{
	int			i;
	int			minus;
	int			zero_count;
	long long	num;

	minus = 0;
	if (str[0] == '-')
		minus++;
	if (str[minus] == '\0' || str[minus] == ' ')
		return (0);
	i = 0;
	zero_count = 0;
	while (str[i + minus + zero_count] == '0')
		zero_count++;
	num = 0;
	while (str[i + minus])
	{
		num = (num * 10) + (str[i + minus] - '0');
		if (num - minus > 2147483647 || i - zero_count > 10)
			return (0);
		else if ('0' > str[i + minus] || str[i + minus] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ps_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] != s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
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
			if (!ps_strcmp(av[i], av[comp]))
			{
				ps_av_free(av);
				exit (ft_printf("Error (string dup) \n"));
			}
			comp++;
		}
		i++;
	}
}

int	ps_int_dup_check(int *nums, int ac)
{
	int	i;
	int	comp;

	i = 0;
	while (ac > i)
	{
		comp = i + 1;
		while (ac > comp)
		{
			if (nums[i] == nums[comp])
				return (0);
			comp++;
		}
		i++;
	}
	return(1);
}
