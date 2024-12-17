/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:54:06 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/17 17:10:53 by sipyeon          ###   ########.fr       */
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
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
	}
	ft_printf("sa");
}
void	ft_sb(t_stack *b)
{
	t_list	*first;
	t_list	*second;

	if (b->size >= 2)
	{
		first = b->head;
		second = first->next;
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
	}
	ft_printf("sb");
}
void	ft_ss(t_stack *a, t_stack *b)
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
	if (b->size >= 2)
	{
		first = b->head;
		second = first->next;
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
	}
	ft_printf("ss");
}
