/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fuction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:41:08 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 23:08:07 by sipyeon          ###   ########.fr       */
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
	if (flag == 1)
		ft_printf("sa");
	else if (flag == 2)
		ft_printf("sb");
}

void	ft_push(t_stack *a, t_stack *b, int a_or_b)
{
	if (a_or_b == 'a')
	{
		ft_lstadd_front(a->head, b->head);
		b->head = NULL;
		ft_printf("pa");
	}
	else if (a_or_b == 'b')
	{
		ft_lstadd_front(b->head, a->head);
		a->head = NULL;
		ft_printf("pb");
	}
}

void	ft_rotate(t_stack *stack, int flag)
{
	ft_lstadd_back(stack->tail, stack->head);
	if (flag == 'a')
		ft_printf("ra");
	else if (flag == 'b')
		ft_printf("rb");
}

void	ft_rr(t_stack *stack, int flag)
{
	ft_lstadd_front(stack->head, stack->tail);
	stack->tail = NULL;
	if (flag == 'a')
		ft_printf("ra");
	else if (flag == 'b')
		ft_printf("rb");
}
