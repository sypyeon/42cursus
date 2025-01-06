/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:54:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/06 20:32:15 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size >= 2)
	{
		// int tmp;

		// tmp = stack->head->nb;
		// stack->head->nb = stack->head->next->nb;
		// stack->head->next->nb = tmp;
		first = stack->head;
		second = first->next;
		stack->head = second;
		first->prev = stack->head;
		first->next = stack->head->next->next;
		second->prev = NULL;
		second->next = first;
		if (stack->size == 2)
			stack->tail = first;
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
