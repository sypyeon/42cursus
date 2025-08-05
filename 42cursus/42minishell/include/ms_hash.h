/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:13:07 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/24 17:48:40 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_HASH_H
# define MS_HASH_H

# define HASH_POW 31
# define HASH_SIZE 53
# define MS_EXIT_CODE "?"

typedef struct s_hash_node
{
	char				*key;
	char				*value;
	struct s_hash_node	*next;
}	t_hash_node;

typedef struct s_hash_list
{
	t_hash_node	*head;
	t_hash_node	*tail;
}	t_hash_list;

typedef struct s_hash
{
	t_hash_list	hash_table[HASH_SIZE];
	int			size;
}	t_hash;

int			get_index(char *key);
void		init_hash(char **env, t_hash *hash);
t_hash_node	*get_new_node(char *key, char *value);
void		list_add_back(t_hash_list *hash_list, t_hash_node *new_node);

char		**change_hash(t_hash hash);

void		free_split(char **temp);
void		free_hash(t_hash *hash);

#endif