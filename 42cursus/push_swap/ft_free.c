/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:46:42 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/08 19:24:48 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
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

void	ft_free(void *to_free)
{
	if (to_free)
		free(to_free);
	to_free = NULL;
}

void	ft_av_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		ft_free(to_free[i]);
		i++;
	}
	ft_free(to_free);
}