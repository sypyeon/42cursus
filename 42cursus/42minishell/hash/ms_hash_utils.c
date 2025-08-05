/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hash_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:30:33 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/28 18:16:30 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_hash.h"
#include "libft.h"

static char	*make_env_string(char *s1, char *s2)
{
	char	*envstr;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	envstr = (char *)ft_calloc(s1_len + s2_len + 2, sizeof(char));
	ft_memcpy(envstr, s1, s1_len);
	ft_memcpy((envstr + s1_len), "=", 1);
	ft_memcpy((envstr + s1_len + 1), s2, s2_len);
	return (envstr);
}

char	**change_hash(t_hash hash)
{
	char		**env;
	t_hash_node	*cur;
	int			i;
	int			j;

	i = 0;
	j = 0;
	env = (char **)ft_calloc(hash.size + 1, sizeof(char *));
	if (env == NULL)
		return (NULL);
	while (i < HASH_SIZE)
	{
		cur = hash.hash_table[i].head;
		while (cur != NULL)
		{
			env[j] = make_env_string(cur->key, cur->value);
			j++;
			cur = cur->next;
		}
		i++;
	}
	env[j] = NULL;
	return (env);
}
