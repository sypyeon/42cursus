/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:19:11 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/24 21:47:26 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *to, t_stack *from)
{
	t_list	*from_head;
	t_list	*to_head;

	from_head = from->head;
	to_head = to->head;
	if (from_head->next)
		from_head->next->prev = NULL;
	from->head = from_head->next;
	from_head->next = to_head;
	if (to_head)
		to_head->prev = from_head;
	else
		to->tail = from->head;
	to->head = from->head;
	to->size++;
	from->size--;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (b->size >= 2)
	{
		ft_push(a, b);
		ft_printf("pa\n");
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (a->size >= 2)
	{
		ft_push(b, a);
		ft_printf("pb\n");
	}
}
