/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:33:10 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/28 01:16:40 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PIPE_H
# define MS_PIPE_H

# include "ms_parse.h"
# include "ms_signal.h"
# include "ms_struct.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

void	main_pipe(t_ms_info *cmd_info, t_hash *hash);
void	dup_setting(t_cmd *cmd);
void	ms_run_input(t_ms_info *info, t_hash *hash);
int		builtin_check(t_cmd *cmd, t_hash *hash, int flag, t_ms_info *info);
void	access_check(t_cmd *cmd, t_ms_info *info, t_hash *hash);
void	sigint_exitcode_setting(t_hash *hash, int status);
void	process_exitcode_setting(char **argv, char **envp);
void	pipe_close(t_cmd *cmd);
char	*ms_replace_heredoc_env(char *str, t_hash *hash);

#endif