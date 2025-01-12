/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:46:42 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/10 17:22:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_stack(t_stack *stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	if (stack)
		free(stack);
}

void	ps_free(void *to_free)
{
	if (to_free)
		free(to_free);
	to_free = NULL;
}

void	ps_av_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		ps_free(to_free[i]);
		i++;
	}
	ps_free(to_free);
}
