/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:40:41 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/23 19:03:47 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_list	*first;
	t_list	*last;

	if (a->size >= 2)
	{
		last = a->head;
		first = last->prev;
		first->prev = NULL;
		last->prev = a->tail;
		last->next = NULL;
		ft_printf("ra");
	}
}

void	ft_rb(t_stack *b)
{
	t_list	*first;
	t_list	*last;

	if (b->size >= 2)
	{
		last = b->head;
		first = last->prev;
		first->prev = NULL;
		last->prev = b->tail;
		last->next = NULL;
		ft_printf("rb");
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	t_list	*first;
	t_list	*last;

	if (a->size >= 2 && b->size >= 2)
	{
		last = a->head;
		first = last->prev;
		first->prev = NULL;
		last->prev = a->tail;
		last->next = NULL;
		ft_printf("rr");
	}
}
