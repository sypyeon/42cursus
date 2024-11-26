/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fuction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:41:08 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/26 23:52:28 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, int flag)
{
	t_list *head;
	t_list *second;

	if (stack->size < 2)
		return ;
	head = stack->head;
	second = head->next;
	head->next = second->next;
	head->prev = second;
	second->next = head;
	second->prev = NULL;
	if (flag == 1)
		ft_printf("sa");
	else if (flag == 2)
		ft_printf("sb");
}

void	ft_push()
{
	
}

void	ft_rotate()
{
	
}

void	ft_rr()
{
	
}
