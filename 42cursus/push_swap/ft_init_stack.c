/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:39:27 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/23 16:38:12 by sipyeon          ###   ########.fr       */
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

t_stack	*ft_newstack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->size = 0;
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}

t_stack	*ft_init_stack(int *nums, int ac)
{
	int		i;
	t_list	*add;
	t_stack	*stack;

	stack = ft_newstack();
	i = 0;
	while(i < ac)
	{
		add = ft_lstnew_nb(nums[i]);
		ft_lstadd_back(&stack->head, add);
		stack->size++;
		i++;
	}
	stack->tail = add;
	return (stack);
}
