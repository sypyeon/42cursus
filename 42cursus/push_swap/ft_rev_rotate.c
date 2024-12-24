/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:43:57 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/24 21:38:32 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	first = stack->tail;
	last = first->prev;
	stack->head->prev = first;
	first->next = stack->head;
	first->prev = NULL;
	last->next = NULL;
	stack->head = first;
	stack->tail = last;
}

void	ft_rra(t_stack *a)
{
	if (a->size >= 2)
		{
			ft_rev_rotate(a);
			ft_printf("rra\n");
		}
}
void	ft_rrb(t_stack *b)
{
	if (b->size >= 2)
		{
			ft_rev_rotate(b);
			ft_printf("rrb\n");
		}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
		ft_printf("rrr");
	}
}
