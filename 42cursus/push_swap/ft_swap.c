/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:54:06 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/23 18:43:24 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	t_list	*first;
	t_list	*second;

	if (a->size >= 2)
	{
		first = a->head;
		second = first->next;
		a->head = second;
		first->prev = second;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		ft_printf("sa\n");
	}
}
void	ft_sb(t_stack *b)
{
	t_list	*first;
	t_list	*second;

	if (b->size >= 2)
	{
		first = b->head;
		second = first->next;
		b->head = second;
		first->prev = second;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		ft_printf("sb\n");
	}
}
void	ft_ss(t_stack *a, t_stack *b)
{
	t_list	*first;
	t_list	*second;

	if (a->size >= 2 && b->size >= 2)
	{
		first = a->head;
		second = first->next;
		a->head = second;
		first->prev = second;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		first = b->head;
		second = first->next;
		b->head = second;
		first->prev = second;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		ft_printf("ss\n");
	}
}
