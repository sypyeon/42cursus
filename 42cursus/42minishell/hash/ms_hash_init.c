/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hash_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:34:40 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/24 23:41:10 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_hash.h"
#include "libft.h"

int	get_index(char *key)
{
	int	code;

	code = 0;
	while (*key)
	{
		code += (*key * HASH_POW);
		code %= HASH_SIZE;
		key++;
	}
	return (code);
}

t_hash_node	*get_new_node(char *key, char *value)
{
	t_hash_node	*new_node;

	new_node = (t_hash_node *)ft_calloc(sizeof(t_hash_node), 1);
	new_node->key = ft_strdup(key);
	if (value == NULL)
		new_node->value = ft_strdup("");
	else
		new_node->value = ft_strdup(value);
	return (new_node);
}

void	list_add_back(t_hash_list *hash_list, t_hash_node *new_node)
{
	if (hash_list->head == NULL)
	{
		hash_list->head = new_node;
		hash_list->tail = new_node;
	}
	else
	{
		hash_list->tail->next = new_node;
		hash_list->tail = new_node;
	}
}

void	init_hash(char **env, t_hash *hash)
{
	char	**parse_env;
	int		i;

	i = 0;
	ft_bzero(hash, sizeof(t_hash));
	while (env[i])
	{
		parse_env = ft_split(env[i], '=');
		list_add_back(&(hash->hash_table[get_index(parse_env[0])]),
			get_new_node(parse_env[0], parse_env[1]));
		hash->size++;
		free_split(parse_env);
		i++;
	}
	list_add_back(&(hash->hash_table[get_index(MS_EXIT_CODE)]),
		get_new_node(MS_EXIT_CODE, "0"));
	list_add_back(&(hash->hash_table[get_index("0")]),
		get_new_node("0", "minishell"));
	hash->size = hash->size + 2;
}
