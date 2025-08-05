/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc_sinal_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:29:29 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/26 14:34:59 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_signal.h"
#include <termio.h>

void	heredoc_signal_handle(int signum)
{
	int	eof;

	if (signum == SIGINT)
	{
		rl_replace_line("", 1);
		write(STDOUT_FILENO, "^C", 2);
		eof = open("/dev/null", O_RDONLY);
		dup2(eof, STDIN_FILENO);
		close(eof);
		g_ms_signum = signum;
	}
}

void	heredoc_signal(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, heredoc_signal_handle);
}
