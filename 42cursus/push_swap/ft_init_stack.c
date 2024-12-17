/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:39:27 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/17 20:20:01 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_init_stack(int *nums, int ac)
{
	int		i;
	t_list	*add;
	t_stack	*stack;

	ft_lstnew()
	i = 0;
	while(i < ac)
	{
		add->nb = nums[i];
		ft_lstadd_back(stack->tail, add);
		i++;
	}
}