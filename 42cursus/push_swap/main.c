/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:08:24 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/22 23:15:13 by sipyeon          ###   ########.fr       */
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
	if (str[i] == '-')
		i++;
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

#include<stdio.h>

int	main(int ac, char **av)
{
	int 	*nums;
	t_stack	*a;
	t_stack	*b;

	if (ac < 3)
		return(0);
	ac--;
	nums = ft_arr_atoi(ac, av);
	ft_check_valid(nums);
	nums = ft_arrange_nums(ac, nums);
	a = ft_init_stack(nums, ac);
	b = ft_init_stack(NULL, ac);
	for(int j = 0; j < ac; ++j)
	{
		ft_printf("%d\n", nums[j]);
	}
	printf("------------------------------\n");
    t_list *now;
    t_list *now2;
    int    d;
    now = a->head;
    now2 = b->head;
    d = 1;
    while (a->size - d + 1 > 0 || b->size - d + 1> 0)
    {
        if(a->size - d + 1 > 0 && b->size - d + 1 > 0)
            printf("%d = b :%d    a :%d\n",d, now2->nb, now->nb);
        else if (a->size - d + 1 > 0)
            printf("%d = b :     a :%d\n",d, now->nb);
        else if (b->size - d + 1 > 0)
            printf("%d = b :%d    a :\n",d, now2->nb);
        d++;
        if (now)
            now = now->next;
        if (now2)
            now2 = now2->next;
    }
    printf("------------------------------\n");
	return (0);
}