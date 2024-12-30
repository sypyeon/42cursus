/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:54:06 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/30 19:39:57 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size >= 2)
	{
		first = stack->head;
		second = first->next;
		if (second == stack->tail)
			stack->tail = first;
		stack->head = second;
		first->prev = second;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
	}
}

void	ft_sa(t_stack *a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack *b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
