/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:02:48 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/10 20:56:06 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_int_dup(int *nums, int ac)
{
	int	i;
	int	*dup;

	i = 0;
	dup = (int *)malloc(sizeof(int) * ac);
	if (!(dup))
		return (0);
	while (i < ac)
	{
		dup[i] = nums[i];
		i++;
	}
	dup[i] = '\0';
	for(int j = 0; j < 5; ++j)
	{
		ft_printf("%d\n", dup[j]);
	}
	return (dup);
}

int	*ft_bsort(int *num)
{
	int	i;
	int	compare_i;
	int	temp;

	i = 0;
	compare_i = 0;
	while (num[i])
	{
		compare_i = i + 1;
		while (num[compare_i])
		{
			if (num[i] > num[compare_i])
			{
				temp = num[i];
				num[i] = num[compare_i];
				num[compare_i] = temp;
			}
			compare_i++;
		}
		i++;
	}
	return (num);
}

int *ft_minimize_num(int *nums, int ac)
{
	int	i;
	int	min_num;
	int	*sorted_nums;

	sorted_nums = ft_bsort(ft_int_dup(nums, ac));
	min_num = 0;
	while (sorted_nums[min_num])
	{
		i = 0;
		while (nums[i])
		{
			if (nums[i] == sorted_nums[min_num])
			{
				nums[i] = min_num;
				break;
			}
			i++;
		}
		min_num++;
	}
	free(sorted_nums);
	return(nums);
}

int	*ft_arrange_nums(int ac, char **av)
{
	int	i;
	int	*nums;

	nums = (int *)malloc(sizeof(int) * (ac));
	if (!nums)
		return (0);
	i = 1;
	while (av[i])
	{
		nums[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return(ft_minimize_num(nums, ac));
}

int	main(int ac, char **av)
{
	// int 	i;
	// int 	*nums;
	// t_stack	a;
	// t_stack	b;

	if (ac < 2)
		return (0);
	ft_arrange_nums(ac, av);
	// i = 0;
	// for(int j = 0; j < ac - 1; ++j)
	// {
	// 	ft_printf("%d\n", nums[j]);
	// }
	return (0);
}
