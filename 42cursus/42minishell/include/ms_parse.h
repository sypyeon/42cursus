/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:30:53 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 23:21:44 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSE_H
# define MS_PARSE_H

# define INPUT		1
# define OUTPUT		2
# define HEREDOC	3
# define APPEND		4

# include "ms_hash.h"
# include "ms_struct.h"
# include "ms_free.h"
# include "libft.h"

int		ms_is_blank(char c);
int		ms_is_upper(int c);
int		ms_is_lower(int c);
int		ms_is_num(int c);
int		ms_is_quote(char c);
int		ms_find_dollar_sign(char *str);

int		ms_is_in_redir(char *str, int index);
int		ms_is_out_redir(char *str, int index);
int		ms_is_redir(char *str, int index);
char	*ms_redir_check(char *arg, t_cmd *cmd);
void	ms_apply_redirection(t_cmd *cmd, t_hash *hash);

int		ms_strcmp(char *str, char *cmp);
int		ms_skip_single_quote(char *str, int i);
int		ms_next_quote(char *line, int i);
int		ms_check_pipe(char *input);
char	*ms_remove_quote(char *str);

char	*ms_strdup_range(char *str, int start, int end);
char	**ms_split(char *to_split, char delimiter);
char	**ms_split_dup(char **split);

char	*ms_replace_env_str(char *str, t_hash *hash);
void	ms_set_env_val(t_cmd *cmd, t_hash *hash);

#endif