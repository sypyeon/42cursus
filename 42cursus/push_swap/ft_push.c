/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:19:11 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/06 20:02:52 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack *to, t_stack *from)
{
	t_list	*from_first;
	t_list	*to_first;

	from_first = from->head;
	to_first = to->head;
	if (from_first->next)
		from_first->next->prev = NULL;
	from->head = from_first->next;
	from_first->next = to_first;
	if (to_first)
		to_first->prev = from_first;
	else
		to->tail = from_first;
	to->head = from_first;
	to->size++;
	from->size--;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (b->size >= 1)
	{
		ft_push(a, b);
		ft_printf("pa\n");
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (a->size >= 1)
	{
		ft_push(b, a);
		ft_printf("pb\n");
	}
}
