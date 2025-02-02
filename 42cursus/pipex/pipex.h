/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:34:15 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/02 22:22:09 by sipyeon          ###   ########.fr       */
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
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

typedef	struct	s_cmd_info
{
	int		size;
	int		in_fd;
	char	*in_file;
	int		out_fd;
	char	*out_file;
	char	**path;
	t_cmd	*head;
	t_cmd	*tail;
}				t_cmd_info;


#endif
