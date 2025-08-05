/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:01:57 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 21:15:42 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ms_env.h"
# include "ms_builtin.h"
# include "ms_hash.h"
# include "ms_struct.h"
# include "ms_signal.h"
# include "ms_pipe.h"

# define HEREDOC_SIG	1
# define SYNTAX_ERR		2

void	ms_cmd_info_init(t_ms_info *info, char *input, t_hash *hash);

#endif
