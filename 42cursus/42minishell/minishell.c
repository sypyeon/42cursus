/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:52:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/25 17:22:59 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

int	ms_is_empty(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ms_is_blank(input[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ms_prompt_loop(t_hash *hash)
{
	char		*input;
	t_ms_info	info;

	while (1)
	{
		ft_bzero(&info, sizeof(t_ms_info));
		readline_signal_handel();
		input = readline("minishell$ ");
		if (input == NULL)
			ms_builtin_exit(hash, &info);
		if (!ms_is_empty(input))
		{
			add_history(input);
			if (g_ms_signum != 0)
				set_path(hash, MS_EXIT_CODE, ft_itoa(g_ms_signum + 128));
			g_ms_signum = 0;
			signal_lock();
			ms_cmd_info_init(&info, input, hash);
			ms_run_input(&info, hash);
		}
		ms_free_info(&info);
	}
	printf("exit\n");
}

int	main(int ac, char **av, char **envp)
{
	t_hash	hash;

	(void)ac;
	(void)av;
	init_hash(envp, &hash);
	ms_prompt_loop(&hash);
	return (0);
}
