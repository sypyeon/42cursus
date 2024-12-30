/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:40:41 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/30 20:02:27 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack *stack)
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
		return (1);
	}
	return (0);
}

void	ft_ra(t_stack *a)
{
	if (ft_rotate(a))
		ft_printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	if (ft_rotate(b))
		ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
