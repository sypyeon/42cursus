/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:40:41 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/07 14:52:17 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	t_list	*tail;
	t_list	*first;

	tail = stack->head;
	first = stack->head->next;
	tail->prev = stack->tail;
	stack->tail = tail;
	stack->tail->prev->next = tail;
	tail->next = NULL;
	stack->head = first;
	first->prev = NULL;
}

void	ft_ra(t_stack *a)
{
	if (a->size >= 2)
	{
		ft_rotate(a);
		ft_printf("ra\n");
	}
}

void	ft_rb(t_stack *b)
{
	if (b->size >= 2)
	{
		ft_rotate(b);
		ft_printf("rb\n");
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
