/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:02:48 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/10 00:19:47 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bsort(int *num)
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
			if (num[i] < num[compare_i])
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

int *ft_minimize_num(int *nums)
{
	int	i;
	int	min_num;
	int	*sorted_nums;
	int	*temp;

	sorted_nums = ft_strdup(nums);
	ft_bsort(sorted_nums);
	i = 0;
	min_num = 0;
	while (sorted_nums[min_num])
	{
		while (nums[i])
		{
			if (nums[i] == sorted_nums[min_num])
				nums[i] = min_num;
			i++;
		}
		min_num++;
	}
	return(nums);
}

int	*ft_dup_num(int ac, char **av)
{
	int	i;
	int	*nums;
	
	nums = (int *)malloc(sizeof(int) * (ac - 1));
	i = 0;
	while (av[i])
	{
		nums[i] = ft_atoi(av[i]);
		i++;
	}
	ft_minimize_num(nums);
	
}

int	main(int ac, char **av)
{
	int 	i;
	int 	*nums;
	t_stack	a;
	t_stack	b;

	if (ac != 2)
		return (0);
	nums = ft_dup_num(ac, av);
	i = 0;
	while (nums[i])
	{
		ft_printf("%s", nums[i]);
		i++;
	}
	return (0);
}
