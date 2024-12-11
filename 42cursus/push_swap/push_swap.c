/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:02:48 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/11 18:03:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

unsigned int	*ft_int_dup(unsigned int *nums, int ac)
{
	int				i;
	unsigned int	*dup;

	i = 0;
	dup = (unsigned int *)malloc(sizeof(unsigned int) * ac);
	if (!(dup))
		return (0);
	while (i < ac)
	{
		dup[i] = nums[i];
		i++;
	}
	for(int j = 0; j < 8; ++j)
	{
		printf("%u\n", dup[j]);
	}
	return (dup);
}

unsigned int	*ft_bsort(unsigned int *nums)
{
	unsigned int	i;
	unsigned int	compare_i;
	unsigned int	temp;

	i = 0;
	compare_i = 0;
	while (nums[i])
	{
		compare_i = i + 1;
		while (nums[compare_i])
		{
			if (nums[i] > nums[compare_i])
			{
				temp = nums[i];
				nums[i] = nums[compare_i];
				nums[compare_i] = temp;
			}
			compare_i++;
		}
		i++;
	}
	return (nums);
}

unsigned int	*ft_minimize_num(unsigned int *nums, int ac)
{
	unsigned int	i;
	unsigned int	min_num;
	unsigned int	*sorted_nums;

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

unsigned int	*ft_arrange_nums(int ac, char **av)
{
	int				i;
	unsigned int	*nums;

	nums = (unsigned int *)malloc(sizeof(unsigned int) * (ac));
	if (!nums)
		return (0);
	i = 1;
	while (av[i])
	{
		nums[i - 1] = (unsigned int)ft_atoi(av[i]) + INT_MAX;
		i++;
	}
	return(ft_minimize_num(nums, ac));
}

void	ft_check_valid()
{
	
}

int	main(int ac, char **av)
{
	// int 	i;
	// int 	*nums;
	// t_stack	a;
	// t_stack	b;

	ft_check_valid();
	ft_arrange_nums(ac, av);
	// i = 0;
	// for(int j = 0; j < ac - 1; ++j)
	// {
	// 	ft_printf("%d\n", nums[j]);
	// }
	return (0);
}
