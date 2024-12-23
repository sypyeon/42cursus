/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:19:11 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/23 23:08:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	t_list	*a_first;
	t_list	*b_first;

	if (b->size > 0)
	{
		a_first = a->head;
		b_first = b->head;
		if (b_first->next)
			b_first->next->prev = NULL;
		b->head = b_first->next;
		b_first->next = a_first;
		if (a_first)
			a_first->prev = b_first;
		else
			a->tail = b_first;
		a->head = b_first;
		a->size++;
		b->size--;
		ft_printf("pa\n");
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_list	*b_first;
	t_list	*a_first;

	if (a->size > 0)
	{
		b_first = b->head;
		a_first = a->head;
		if (a_first->next)
			a_first->next->prev = NULL;
		a->head = a_first->next;
		a_first->next = b_first;
		if (b_first)
			b_first->prev = a_first;
		else
			b->tail = a_first;	
		b->head = a_first;
		a->size--;
		b->size++;
		ft_printf("pb\n");
	}
}
