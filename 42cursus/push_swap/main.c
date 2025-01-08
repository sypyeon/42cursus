/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:08:24 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/08 20:23:52 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*nums;
	t_stack	*a;
	t_stack	*b;

	if (ac <= 1)
		return (0);
	av = ps_split(av);
	ft_check_valid(av);
	ac = 0;
	while (av[ac + 1])
		ac++;
	nums = ft_arrange_nums(ac, ft_arr_atoi(ac, av));
	ft_av_free(av);
	a = ft_init_stack(nums, ac);
	b = ft_newstack();
	ps_sort(a, b, ac);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
