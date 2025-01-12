/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:54:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/10 17:16:42 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size >= 2)
	{
		second = stack->head;
		first = stack->head->next;
		if (stack->size > 2)
			first->next->prev = second;
		second->next = first->next;
		second->prev = first;
		first->next = second;
		first->prev = NULL;
		stack->head = first;
		stack->head->next = second;
		if (stack->size == 2)
			stack->tail = second;
	}
}

void	ft_sa(t_stack *a)
{
	if (a->size >= 2)
	{
		ft_swap(a);
		ft_printf("sa\n");
	}
}

void	ft_sb(t_stack *b)
{
	if (b->size >= 2)
	{
		ft_swap(b);
		ft_printf("sb\n");
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		ft_swap(a);
		ft_swap(b);
		ft_printf("ss\n");
	}
}
