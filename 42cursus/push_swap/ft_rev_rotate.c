/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:43:57 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/23 19:02:00 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	t_list	*first;
	t_list	*last;

	if (a->size >= 2)
	{
		first = a->tail;
		last = first->prev;
		last->next = NULL;
		a->head->prev = first;
		first->next = a->head;
		first->prev = NULL;
		a->head = first;
		a->tail = last;
		ft_printf("rra");
	}
}

void	ft_rrb(t_stack *b)
{
	t_list	*first;
	t_list	*last;

	if (b->size >= 2)
	{
		first = b->tail;
		last = first->prev;
		last->next = NULL;
		first->next = b->head;
		b->head = first;
		b->tail = last;
		first->prev = NULL;
		ft_printf("rrb");
	}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	t_list	*first;
	t_list	*last;

	if (a->size >= 2 && b->size >= 2)
	{
		first = a->tail;
		last = first->prev;
		a->tail = last;
		last->next = NULL;
		first->next = a->head;
		a->head = first;
		first->prev = NULL;

		first = b->tail;
		last = first->prev;
		b->tail = last;
		last->next = NULL;
		first->next = b->head;
		b->head = first;
		first->prev = NULL;
		ft_printf("rrr");
	}
}
