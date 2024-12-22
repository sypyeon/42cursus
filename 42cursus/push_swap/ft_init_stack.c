/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:39:27 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/22 23:19:30 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_nb(int nb)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->nb = nb;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_newstack(int nb)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->size = nb;
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}

t_stack	*ft_init_stack(int *nums, int ac)
{
	int		i;
	t_list	*add;
	t_stack	*stack;

	add = ft_lstnew_nb(nums[0]);
	stack->head = add;
	i = 1;
	while(i < ac)
	{
		add = ft_lstnew_nb(nums[i]);
		ft_lstadd_back(stack->head, add);
		i++;
	}
	stack->tail = add;
}