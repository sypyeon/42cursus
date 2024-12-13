/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:08:24 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/13 22:14:22 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_valid(int *nums)
{
	int	i;
	int	comp;

	i = 0;
	while (nums[i])
	{
		comp = i + 1;
		while (nums[comp])
		{
			if (nums[i] == nums[comp])
				exit (ft_printf("Error"));
			comp++;
		}
		i++;
	}
}

static void	ft_is_numstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ('0' > str[i] || str[i] > '9')
		{
			ft_printf("Error");
			exit(1);
		}
		i++;
	}
}

int *ft_arr_atoi(int ac, char **av)
{
	int	i;
	int *int_arr;

	int_arr = (int *)malloc(sizeof(int) * (ac));
	if (!int_arr)
		return (0);
	i = 1;
	while (av[i])
	{
		ft_is_numstr(av[i]);
		i++;
	}
	i = 0;
	while (av[i + 1])
	{
		int_arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (int_arr);
}

int *ft_minimize(int *nums, int *new_nums, int len)
{
	int	i;
	int	s_num;
	int	s_i;
	int	from_zero;

	from_zero = 0;
	i = 0;
	s_num = INT_MIN;
	while (nums[i])
	{
		if (s_num < nums[i])
		{
			s_num = nums[i];
			s_i = i;
		}
		i++;
	}
	new_nums[s_i] = len - 1;
	i = 0;
	while (from_zero < len)
	{
		i = 0;
		while (nums[i])
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
	for(int j = 0; j < len; ++j)
	{
		ft_printf("%d\n", len);
	}
	return (new_nums);
}

int	*ft_arrange_nums(int ac, int *nums)
{
	int	*new_nums;

	new_nums = (int *)malloc(sizeof(int) * ac);
	if (!new_nums)
		return (0);
	new_nums = ft_minimize(nums, new_nums, ac);
	free(nums);
	return (new_nums);
}

int	main(int ac, char **av)
{
	int 	*nums;

	if (ac < 3)
		return(0);
	nums = ft_arr_atoi(ac - 1, av);
	ft_check_valid(nums);
	nums = ft_arrange_nums(ac - 1, nums);
	// for(int j = 0; j < ac - 1; ++j)
	// {
	// 	ft_printf("%d\n", nums[j]);
	// }
	return (0);
}