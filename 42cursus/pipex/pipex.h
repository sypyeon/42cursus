/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:34:15 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/04 18:41:22 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct	s_cmd
{
	char 			**cmd;
	int				fd[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

typedef	struct	s_cmd_info
{
	int		size;
	int		in_fd;
	int		out_fd;
	int		here_doc;
	char	**path;
	char	*limiter;
	t_cmd	*head;
	t_cmd	*tail;
}				t_cmd_info;

void	px_init_cmd_info(t_cmd_info *cmd_info, int ac, char **av);
t_cmd	*new_cmd(char **cmd);
t_cmd	*last_cmd(t_cmd *lst);
void	cmd_add_back(t_cmd_info *list, t_cmd *new);
void	save_cmd(t_cmd_info *list, int ac, char **av);

int		strcmp_find_path(const char *path, const char *str);
char	**find_path(char **envp);
void	access_check(t_cmd_info *list);

#endif
