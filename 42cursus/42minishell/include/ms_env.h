/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:40:30 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/27 17:01:50 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_H
# define MS_ENV_H

# include "ms_hash.h"

void	del_path(t_hash *hash, char *key);
void	set_path(t_hash *hash, char *key, char *value);
void	add_path(t_hash *hash, char *path);
char	*get_path(t_hash *hash, char *key);

#endif
