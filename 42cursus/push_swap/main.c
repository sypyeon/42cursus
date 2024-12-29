/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:08:24 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/29 19:55:32 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_is_int(char *str)
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
			exit(ft_printf("Error (cannot fit in int) \n"));
		else if ('0' > str[i + minus] || str[i + minus] > '9')
			exit(ft_printf("Error (not a number) \n"));
		i++;
	}
}

void	ft_check_valid(char **av)
{
	int		i;
	int		comp;

	i = 1;
	while (av[i])
	{
		ft_is_int(av[i]);
		comp = i + 1;
		while (av[comp])
		{
			if (!ft_strncmp(av[i], av[comp], 11))
				exit (ft_printf("Error (same numbers) \n"));
			comp++;
		}
		i++;
	}
}

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

int	*ft_minimize(int *nums, int *new_nums, int len)
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

void	ft_free(void *to_free)
{
	if (to_free)
		free(to_free);
	to_free = NULL;
}

char	**ps_split(char **av)
{
	char	*str;
	int		i;
	
	i = 0;
	while (av[i])
	{
		str = ft_strjoin(str, ft_strjoin(av[i], " "));
		i++;
	}
	av = ft_split(str, ' ');
	ft_free(str);
	return (av);
}

void	ft_free_stack(t_stack *stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	// if (stack)
	// 	free(stack);
}

int	main(int ac, char **av)
{
	int		*nums;
	t_stack	*a;
	t_stack	*b;

	av = ps_split(av);
	ac = 0;
	while (av[ac + 1])
		ac++;
	ft_check_valid(av);
	nums = ft_arrange_nums(ac, ft_arr_atoi(ac, av));
	a = ft_init_stack(nums, ac);
	b = ft_newstack();
	ft_check_sorting_functions(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
