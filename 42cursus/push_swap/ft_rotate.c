/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:40:41 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/24 00:03:50 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_list	*first;
	t_list	*last;

	if (a->size == 2)
		ft_sa(a);
	else if (a->size > 2)
	{
		last = a->head;
		first = last->next;
		a->head = first;
		a->tail->next = last;
		last->next = NULL;
		a->tail = last;
		first->prev = NULL;
		ft_printf("ra\n");
	}
}

void	ft_rb(t_stack *b)
{
	t_list	*first;
	t_list	*last;

	// if (b->size == 2)
	// 	ft_sb(b);
	if (b->size >= 2)
	{
		last = b->head;
		first = last->next;
		b->head = first;
		b->tail->next = last;
		last->next = NULL;
		b->tail = last;
		first->prev = NULL;
		ft_printf("rb\n");
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	t_list	*first;
	t_list	*last;

	if (a->size >= 2 && b->size >= 2)
	{
		last = a->head;
		first = last->next;
		a->head = first;
		a->tail->next = last;
		last->next = NULL;
		a->tail = last;
		first->prev = NULL;
		last = b->head;
		first = last->next;
		b->head = first;
		b->tail->next = last;
		last->next = NULL;
		b->tail = last;
		first->prev = NULL;
		ft_printf("rr\n");
	}
}
