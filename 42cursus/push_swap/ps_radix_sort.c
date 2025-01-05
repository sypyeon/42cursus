/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:51:11 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/05 18:30:21 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_align(t_stack *a, int ac)
{
	t_list	*now;

	if (ac > a->size)
		return (1);
	now = a->head;
	while (now->next)
	{
		if (now->nb > now->next->nb)
			return (0);
		now = now->next;
	}
	return (1);
}

void	ps_greedy_sort(t_stack *stack_a, t_stack *stack_b, int ac)
{
	t_list	*a;
	int		i;

	a = stack_a->head;
	i = stack_a->size - 1;
	while (3 <= stack_a->size)
	{
		if (a->nb != 0 || a->nb != i || a->nb != i / 2)
			ft_pb(stack_a, stack_b);
	}
	while (stack_b->size)
	{
		if ()	
		ft_pa(stack_a, stack_b);
	}
	while (!ft_stack_align(stack_a, ac))
	{
		i = 0;
		while (i < stack_a->size)
		{
			
		}
	}
	
}

int	ps_radix_sort(t_stack *stack_a, t_stack *stack_b, int ac)
{
	t_list	*a;
	int		bit;
	int		i;
	int		size;

	bit = 1;
	size = stack_a->size;
	while (!ft_stack_align(stack_a, ac))
	{
		i = 0;
		while (i < size)
		{
			a = stack_a->head;
			if (!(a->nb & bit))
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
			i++;
		}
		while (stack_b->size)
			ft_pa(stack_a, stack_b);
		bit = bit << 1;
	}
	return (0);
}
