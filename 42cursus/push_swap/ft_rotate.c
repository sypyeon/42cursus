/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:40:41 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/24 20:46:06 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size >= 2)
	{
		first = stack->head;
		second = first->next;
		stack->head = second;
		first->prev = stack->tail;
		stack->tail->next = first;
		first->next = NULL;
		stack->tail = first;
		second->prev = NULL;
		ft_printf("ra\n");
	}
}

void	ft_ra(t_stack *a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
