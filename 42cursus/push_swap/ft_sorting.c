/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:51:11 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/29 21:53:21 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_align(t_stack *a, int ac)
{
	t_list	*now;

	if (ac > a->size)
		return (1);
	now = a->head;
	while (now->next)
	{
		if (now->nb > now->next->nb)
			return (0);
		now = now->next;
	}
	return (1);
}

void	ps_greedy(t_stack *a, t_stack *b)
{
	
}

void	ft_how_big(t_stack *a)
{
	
}

int	ft_what_to_do(t_stack *a, t_stack *b, int ac)
{
	int	i;

	while (!ft_stack_align(a, ac))
	{
		
	}
}
