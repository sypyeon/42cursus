/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fuction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:41:08 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/29 00:15:16 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, int flag)
{
	t_list *first;
	t_list *second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (flag == 'a')
		ft_printf("sa");
	else if (flag == 'b')
		ft_printf("sb");
}

void	ft_push(t_stack *a, t_stack *b, int a_or_b)
{
	t_list	*a_first;
	t_list	*b_first;

	if (a->size < 2 || b->size < 2)
		return ;
	b_first = b->head;
	a_first = a->head;
	if (a_or_b == 'a')
	{
		b_first->next = a_first;
		ft_printf("pa");
	}
	else if (a_or_b == 'b')
	{
		a_first->next = b_first;
		ft_printf("pb");
	}
}

void	ft_rotate(t_stack *stack, int flag)
{
	t_list	*first;
	t_list	*last;

	if (stack->size < 2)
		return ;
	last = stack->head;
	first = last->prev;
	first->prev = NULL;
	last->prev = stack->tail;
	last->next = NULL;
	if (flag == 'a')
		ft_printf("ra");
	else if (flag == 'b')
		ft_printf("rb");
}

void	ft_rr(t_stack *stack, int flag)
{
	t_list	*first;
	t_list	*last;

	if (stack->size < 2)
		return ;
	first = stack->tail;
	last = first->prev;
	last->next = NULL;
	first->next = stack->head;
	first->prev = NULL;
	if (flag == 'a')
		ft_printf("rra");
	else if (flag == 'b')
		ft_printf("rrb");
}
