/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:22:20 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/27 17:03:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define MS_SIGNAL_H

# include "ms_hash.h"
# include "ms_env.h"
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>

extern int	g_ms_signum;

void	readline_signal_handel(void);
void	signal_lock(void);
void	signal_unlock(void);
void	heredoc_signal(void);

#endif