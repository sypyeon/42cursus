/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:34:15 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/30 23:00:11 by sipyeon          ###   ########.fr       */
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
	int				pipe_fd[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

typedef	struct	s_cmd_info
{
	int		size;
	int		in_fd;
	int		out_fd;
	char	**path;
	t_cmd	*head;
	t_cmd	*tail;
}				t_cmd_info;


#endif
