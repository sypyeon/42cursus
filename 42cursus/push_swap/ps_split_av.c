/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:23:44 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/10 17:30:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_arr_atoi(int ac, char **av)
{
	int	i;
	int	*int_arr;

	int_arr = (int *)malloc(sizeof(int) * (ac));
	if (!int_arr)
		return (0);
	i = 0;
	while (av[i + 1])
	{
		int_arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (int_arr);
}

int	*ft_indexing(int *nums, int *new_nums, int len, int s_num)
{
	int	i;
	int	s_i;
	int	from_zero;

	from_zero = 0;
	while (from_zero < len - 1)
	{
		i = 0;
		s_num = INT_MAX;
		while (i < len)
		{
			if (s_num > nums[i])
			{
				s_num = nums[i];
				s_i = i;
			}
			i++;
		}
		new_nums[s_i] = from_zero;
		nums[s_i] = INT_MAX;
		from_zero++;
	}
	return (new_nums);
}

int	*ft_minimize(int *nums, int *new_nums, int len)
{
	int	i;
	int	s_num;
	int	s_i;

	i = 0;
	s_num = INT_MIN;
	while (i < len)
	{
		if (s_num < nums[i])
		{
			s_num = nums[i];
			s_i = i;
		}
		i++;
	}
	new_nums[s_i] = len - 1;
	nums[s_i] = INT_MAX;
	return (ft_indexing(nums, new_nums, len, s_num));
}

int	*ft_arrange_nums(int ac, int *nums)
{
	int	*new_nums;

	new_nums = (int *)malloc(sizeof(int) * ac);
	if (!new_nums)
		return (0);
	new_nums = ft_minimize(nums, new_nums, ac);
	ps_free(nums);
	return (new_nums);
}

char	**ps_split(char **av)
{
	char	*str;
	char	*temp;
	char	*str_temp;
	int		i;

	i = 0;
	str = ft_strdup("");
	while (av[i])
	{
		temp = ft_strjoin(av[i], " ");
		str_temp = str;
		str = ft_strjoin(str, temp);
		ps_free(temp);
		ps_free(str_temp);
		i++;
	}
	av = ft_split(str, ' ');
	ps_free(str);
	return (av);
}
