/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:37:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/30 17:47:48 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	cmd_add_back(t_cmd_info *lst, t_cmd *new)
{
	t_cmd	*back;

	if (!new)
		return ;
	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	back = lst->tail;
	back->next = new;
}

void	save_cmd(t_cmd_info *list, char **av)
{
	int		i;
	t_cmd	*new;
	t_cmd	*prev;

	i = 0;
	new = new_cmd();
	list->head = new;
	list->in = av[1];
	list->out = av[list->size - 1];
	prev = NULL;
	while (i < list->size - 1)
	{
		new = new_cmd
		new->cmd = ft_split(av[2 + i], ' ');
		cmd_add_back(&list->head, new)
		prev = new;
		list->tail = new;
		ft_lstadd_front
		new = new->next;
		new->prev = prev;
		i++;
	}
	new = NULL;
}

void	access_check(t_cmd_info *list)
{
	t_cmd	*check;

	check = list->head;
	while (check)
    if (access(check->cmd[0], F_OK) == 0) 
        printf("The file exists.\n");
	else
        perror("access");
}

int		main(int ac, char **av)
{
	int			i;
	t_cmd_info	list;
	// pid_t		*pid;

	list.size = ac -3;
	// pid = (pid_t *)malloc(sizeof(pid_t) * list->size);
	save_cmd(&list, av);
	i = 0;
	t_cmd	*new = list.head;
	while (new)
	{
		i = 0;
		while (new->cmd[i])
		{
			printf("%s", new->cmd[i]);
			i++;
		}
		new = new->next;
	}
	
	// execve();
	// int			status;
	// if (!pid[i])
	// {
	// 	// child func
	// 	// exit to not go thru parent func
	// 	exit(11);
	// }
	// else
	// {
	// 	//only parents
	// 	waitpid(a, &status, 0);
	// }
	// printf("%d", status);
	// n_fd = 3;
	// dup2(1, n_fd);
	// write(n_fd, "hello", 5);
	// printf("%d", n_fd);
	return (0);
}
