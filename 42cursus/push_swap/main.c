/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:08:24 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/12 17:27:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arrange(int *)
{
	
}

int	ft_check_valid(int *nums)
{
	int	i;
	int	comp;

	i = 0;
	while (nums[i])
	{
		comp = i + 1;
		while (nums[comp])
		{
			if (nums[comp] < nums[i])
				return ();
		}
		
		i++;
	}
	if 
}
int *ft_arr_atoi(int ac, char **av)
{
	int	i;
	int *int_arr;

	int_arr = (int *)malloc(sizeof(int) * (ac - 1));
	i = 0;
	while (av[i + 1])
	{
		int_arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

int	main(int ac, char **av)
{
	// int 	i;
	int 	*nums;

	if (ac < 3)
		return(0);
	nums = ft_arr_atoi(ac, av);
	ft_check_valid(nums);
	ft_arrange_nums(ac, av);
	// i = 0;
	for(int j = 0; j < ac - 1; ++j)
	{
		ft_printf("%d\n", nums[j]);
	}
	return (0);
}