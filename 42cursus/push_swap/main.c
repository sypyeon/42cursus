/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:08:24 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/24 21:42:21 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_check_valid(int ac, char **av)
{
	int	i;
	int	comp;

	i = 0;
	while (i < ac)
	{
		comp = i + 1;
		while (av[comp])
		{
			if (!ft_strncmp(av[i], av[comp], INT_MAX))
				exit (ft_printf("Error(same numbers)"));
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
			exit(ft_printf("Error(not a number)"));
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

void	ft_print_stack(t_stack *a, t_stack *b)
{
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
            printf("%d = a :%d	b :%d\n",d, now->nb, now2->nb);
        else if (b->size - d + 1 > 0)
            printf("%d = a :     b :%d\n",d, now2->nb);
        else if (a->size - d + 1 > 0)
            printf("%d = a :%d	b :\n",d, now->nb);
        d++;
        if (now)
            now = now->next;
        if (now2)
            now2 = now2->next;
    }
    printf("------------------------------\n");
}

int	main(int ac, char **av)
{
	int 	*nums;
	t_stack	*a;
	t_stack	*b;

	if (ac < 3)
		return(0);
	ac--;
	ft_check_valid(ac, av);
	nums = ft_arr_atoi(ac, av);
	nums = ft_arrange_nums(ac, nums);
	a = ft_init_stack(nums, ac);
	b = ft_newstack();
	ft_print_stack(a,b);
	ft_pb(a, b);
	ft_print_stack(a,b);
	ft_pb(a, b);
	ft_print_stack(a,b);
	ft_pb(a, b);
	ft_print_stack(a,b);
	ft_pa(a, b);
	ft_print_stack(a,b);
	ft_sa(a);
	ft_print_stack(a,b);
	ft_sb(b);
	ft_print_stack(a,b);
	ft_ss(a, b);
	ft_print_stack(a,b);
	ft_ra(a);
	ft_print_stack(a,b);
	ft_rb(b);
	ft_print_stack(a,b);
	ft_rr(a, b);
	ft_print_stack(a, b);
	return (0);
}