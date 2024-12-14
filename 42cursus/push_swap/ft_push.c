/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:19:11 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/14 22:19:32 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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