/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cmd_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:19:41 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/04 02:07:16 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	px_init_cmd_info(t_cmd_info *cmd_info, int ac, char **av)
{
	ft_bzero(cmd_info, sizeof(t_cmd_info));
	if ((ac == 6) && (ft_strncmp(av[1], "here_doc", 10)))
		cmd_info->limiter = av[2];
	else
		cmd_info->in_fd = open(av[1], O_RDONLY);
	cmd_info->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

t_cmd	*new_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_cmd	*last_cmd(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	cmd_add_back(t_cmd_info *list, t_cmd *new)
{
	t_cmd	*back;

	if (!new)
		return ;
	if (list->head == NULL)
	{
		list->head = new;
		return ;
	}
	back = list->tail;
	back->next = new;
	list->tail = new;
	new->prev = back;
}

void	save_cmd(t_cmd_info *list, char **av)
{
	int		i;
	t_cmd	*new;

	i = 0;
	while (i < list->size)
	{
		new = new_cmd();
		if (i == 0)
		{
			list->head = new;
			list->tail = new;
		}
		new->cmd = ft_split(av[2 + i], ' ');
		cmd_add_back(list, new);
		i++;
	}
	new = NULL;
}
