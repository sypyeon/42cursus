/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hash_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:38:46 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/24 23:43:21 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_hash.h"
#include <stdlib.h>

void	free_split(char **temp)
{
	int	i;

	if (temp == NULL)
		return ;
	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
}

void	free_hash(t_hash *hash)
{
	int			i;
	t_hash_node	*cur;
	t_hash_node	*temp;

	i = 0;
	while (i < HASH_SIZE)
	{
		cur = hash->hash_table[i].head;
		while (cur)
		{
			temp = cur;
			cur = cur->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
		i++;
	}
}
