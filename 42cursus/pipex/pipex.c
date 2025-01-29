/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:37:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/29 19:31:22 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	save_cmd(t_cmd_info *list, t_cmd *c_ptr, char **av, pid_t *pid)
{
	int		i;
	t_cmd	*prev;

	i = 0;
	list->head = c_ptr;
	while (i < list->size)
	{
		pid[i] = fork();
		c_ptr->cmd = ft_split(av[2 + i], ' ');
		prev = c_ptr;
		list->tail = c_ptr;
		c_ptr = c_ptr->next;
		c_ptr->prev = prev;
		i++;
	}
	c_ptr = NULL;
}

void	access_check(t_cmd_info *list)
{
	t_cmd	*check;

	
    if (access(check->cmd[0], F_OK) == 0) 
        printf("The file exists.\n");
	else
        perror("access");

    return 0;
}

int		main(int ac, char **av)
{
	int			i;
	int			status;
	t_cmd		*c_ptr;
	t_cmd_info	*list;
	pid_t		*pid;

	list->size = ac - 3;
	pid = (pid_t *)malloc(sizeof(pid_t) * list->size);
	save_cmd(list, c_ptr, av, pid);
	if (access < 0)
	{
		free;
		
	}
	execve();
	if (!pid[i])
	{
		// child func
		// exit to not go thru parent func
		exit(11);
	}
	else
	{
		//only parents
		waitpid(a, &status, 0);
	}
	printf("%d", status);
	// n_fd = 3;
	// dup2(1, n_fd);
	// write(n_fd, "hello", 5);
	// printf("%d", n_fd);
	return (0);
}
