/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cmd_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:19:41 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/19 17:56:10 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <errno.h>

void	px_init_cmd_info(t_cmd_info *cmd_info, int ac, char **av)
{
	ft_bzero(cmd_info, sizeof(t_cmd_info));
	if ((ac == 6) && (!ft_strncmp(av[1], "here_doc", 9)))
	{
		cmd_info->limiter = ft_strjoin(av[2], "\n");
		cmd_info->here_doc = 1;
		cmd_info->size = 2;
		cmd_info->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		if (access(av[1], R_OK) == -1)
		{
			perror(av[1]);
			exit(errno);
		}
		cmd_info->in_fd = open(av[1], O_RDONLY);
		if (cmd_info->in_fd < 0)
			perror("file");
		cmd_info->size = ac - 3;
		cmd_info->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
}

t_cmd	*new_cmd(char **cmd)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	cmd_add_back(t_cmd_info *list, t_cmd *new)
{
	if (!list->head)
		list->head = new;
	else
	{
		list->tail->next = new;
		new->prev = list->tail;
	}
	list->tail = new;
	list->size++;
}

void	save_cmd(t_cmd_info *list, int ac, char **av)
{
	int		i;
	t_cmd	*new;

	i = 0;
	if (list->here_doc)
		i++;
	while (i < ac - 3)
	{
		new = new_cmd(ft_split(av[2 + i], ' '));
		if(!new->cmd[0])
		{
			free(new->cmd);
			new->cmd = (char **)ft_calloc(2, sizeof(char *));
			new->cmd[0] = ft_strdup("");
		}
		cmd_add_back(list, new);
		i++;
	}
}
