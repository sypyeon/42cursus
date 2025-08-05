/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:43:05 by seungsch          #+#    #+#             */
/*   Updated: 2025/04/27 23:34:02 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCT_H
# define MS_STRUCT_H
# include <sys/types.h>

typedef struct s_cmd
{
	char			**x_cmd;
	char			**args;
	char			**redir_info;
	pid_t			pid;
	int				redir;
	int				pipe_fd[2];
	int				hd_pipe_fd[2];
	int				in_fd;
	int				out_fd;
	int				here_doc;
	int				eof_quote;
	int				append;
	char			*limiter;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

typedef struct s_ms_info
{
	int		size;
	char	**args;
	char	**path;
	t_cmd	*head;
	t_cmd	*tail;
}				t_ms_info;

#endif
