/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:51:11 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/13 18:56:01 by sipyeon          ###   ########.fr       */
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

void	ps_sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	last;
	
	first = a->head->nb;
	second = a->head->next->nb;
	last = a->tail->nb;
	if (first < second && first < last)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (first > second && first > last)
	{
		ft_ra(a);
		if (last < second && last < first)
			ft_sa(a);
	}
	else if (first < last && first > second)
		ft_sa(a);
	else if (last < first && last < second)
		ft_rra(a);
}

void	ps_sort_five(t_stack *a, t_stack *b)
{
	while (3 < a->size)
	{
		if (a->head->nb == 1 || a->head->nb == 0)
			ft_pb(a, b);
		else
			ft_ra(a);
	}
	if (!(a->head->nb == 2 && a->head->next->nb == 3 && a->tail->nb == 4))
		ps_sort_three(a);
	if (b->head->nb == 0)
		ft_sb(b);
	ft_pa(a, b);
	ft_pa(a, b);
}

void	ps_radix_sort(t_stack *stack_a, t_stack *stack_b, int ac)
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
}

void	ps_sort(t_stack *a, t_stack *b, int ac)
{
	if (ac == 2 && !ft_stack_align(a, ac))
		ft_sa(a);
	if (!ft_stack_align(a, ac))
	{
		if (ac == 3)
			ps_sort_three(a);
		else if (ac == 5)
			ps_sort_five(a, b);
		else
			ps_radix_sort(a, b, ac);
	}
}
