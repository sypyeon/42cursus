/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fuction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:41:08 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/30 20:42:12 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *a, t_stack *b, int flag)
{
	t_list	*first;
	t_list	*second;

	if (a->size >= 2)
	{
		first = a->head;
		second = first->next;
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
	}
	if (flag == 'a')
		ft_printf("sa");
	else if (flag == 'b')
		ft_printf("sb");
	else if (flag == 'c')
		ft_printf("ss");
	if (flag == 'c')
		ft_swap(b, a, ++flag);
}

void	ft_push(t_stack *a, t_stack *b, int flag)
{
	t_list	*a_first;
	t_list	*b_first;

	if (b->size >= 1)
	{
		b_first = b->head;
		a_first = a->head;
		if (b_first->next)
			b_first->next->prev = NULL;
		b->head = b_first->next;
		b_first->next = a_first;
		a_first->prev = b_first;
		a->head = b_first;
	}
	if (flag == 'a')
		ft_printf("pa");
	else if (flag == 'b')
		ft_printf("pb");
}

void	ft_rotate(t_stack *a, t_stack *b, int flag)
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
	}
	if (flag == 'a')
		ft_printf("ra");
	else if (flag == 'b')
		ft_printf("rb");
	else if (flag == 'c')
		ft_rotate(b, a, ++flag);
	else if (flag == 'd')
		ft_printf("rr");
}

void	ft_rr(t_stack *a, t_stack *b, int flag)
{
	t_list	*first;
	t_list	*last;

	if (a->size < 2)
		return ;
	if (a->size >= 2)
	{
		first = a->tail;
		last = first->prev;
		a->tail = last;
		last->next = NULL;
		first->next = a->head;
		a->head = first;
		first->prev = NULL;
	}
	if (flag == 'a')
		ft_printf("rra");
	else if (flag == 'b')
		ft_printf("rrb");
	else if (flag == 'c')
		ft_rr(b, a, ++flag);
	else if (flag == 'd')
		ft_printf("rr");
}
