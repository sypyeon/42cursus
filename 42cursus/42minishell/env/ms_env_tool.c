/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:40:14 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/28 20:55:46 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "ms_env.h"
#include "ms_free.h"

void	case_handling(t_hash_list *list, t_hash_node *prev, t_hash_node *cur)
{
	if (cur == NULL)
		return ;
	if (prev == NULL && cur->next == NULL)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else if (prev == NULL)
		list->head = cur->next;
	else if (cur->next == NULL)
	{
		list->tail = prev;
		list->tail->next = NULL;
	}
	else
		prev->next = cur->next;
	free(cur);
}

void	add_path(t_hash *hash, char *path)
{
	char		**parse_path;
	t_hash_node	*new_node;

	if (ft_strchr(path, '=') != 0)
	{
		parse_path = ft_split(path, '=');
		if (ms_strcmp(get_path(hash, parse_path[0]), "") != 0)
		{
			set_path(hash, parse_path[0], ft_strdup(parse_path[1]));
			ms_free_split(parse_path);
			return ;
		}
		new_node = get_new_node(parse_path[0], parse_path[1]);
		list_add_back(&(hash->hash_table[get_index(parse_path[0])]), new_node);
		hash->size++;
		ms_free_split(parse_path);
	}
}

char	*get_path(t_hash *hash, char *key)
{
	t_hash_list	*list;
	t_hash_node	*cur;

	if (key == NULL)
		return ("");
	list = &hash->hash_table[get_index(key)];
	cur = list->head;
	while (cur != NULL)
	{
		if (ms_strcmp(cur->key, key) == 0)
			return (cur->value);
		cur = cur->next;
	}
	return ("");
}

void	set_path(t_hash *hash, char *key, char *value)
{
	t_hash_list	*list;
	t_hash_node	*cur;
	char		*tmp_value;

	if (key == NULL)
		return ;
	list = &hash->hash_table[get_index(key)];
	cur = list->head;
	while (cur != NULL)
	{
		if (ms_strcmp(cur->key, key) == 0)
		{
			tmp_value = cur->value;
			cur->value = value;
			free(tmp_value);
			return ;
		}
		cur = cur->next;
	}
	list_add_back(list, get_new_node(key, value));
}

void	del_path(t_hash *hash, char *key)
{
	t_hash_list	*list;
	t_hash_node	*prev;
	t_hash_node	*cur;

	if (key == NULL)
		return ;
	list = &hash->hash_table[get_index(key)];
	cur = list->head;
	prev = NULL;
	while (cur != NULL)
	{
		if (ms_strcmp(cur->key, key) == 0)
		{
			free(cur->key);
			free(cur->value);
			case_handling(list, prev, cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
