/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:38:00 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/27 17:04:26 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTIN_H
# define MS_BUILTIN_H

# include "libft.h"
# include "ms_hash.h"
# include "ms_struct.h"
# include "ms_env.h"
# include "ms_parse.h"
# include "ms_free.h"
# include <string.h>
# include <errno.h>

int		ms_builtin_cd(t_hash *hash, char *command);
void	ms_builtin_pwd(t_hash *hash);
void	ms_builtin_unset(t_hash *hash, char **path);
void	ms_builtin_export(t_hash *hash, char **path);
void	ms_builtin_env(t_hash *hash);
void	ms_builtin_echo(t_hash *hash, t_cmd *cmd);
void	ms_builtin_exit(t_hash *hash, t_ms_info *info);
int		ms_is_lowerstring(char *str);
int		ms_is_blackstring(char *str);

#endif
