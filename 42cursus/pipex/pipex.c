/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:37:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/03 00:35:07 by sipyeon          ###   ########.fr       */
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

void	cmd_add_back(t_cmd_info *list, t_cmd *new)
{
	t_cmd	*back;

	if (!new)
		return ;
	if (list == NULL)
	{
		list->head = new;
		return ;
	}
	back = list->tail;
	back->next = new;
}

void	save_cmd(t_cmd_info *list, char **av)
{
	int		i;
	t_cmd	*new;
	t_cmd	*prev;

	list->in_fd = open(av[1], O_RDONLY);
	list->out_fd = open(av[list->size + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	i = 0;
	while (i < list->size)
	{
		new = new_cmd();
		if (prev)
			new->prev = prev;
		if (i == 0)
		{
			list->head = new;
			list->tail = new;
		}
		new->cmd = ft_split(av[2 + i], ' ');
		cmd_add_back(list, new);
		prev = new;
		list->tail = new;
		i++;
	}
	new = NULL;
}

void	access_check(t_cmd_info *list)
{
	int		i;
	char	*cmd;
	char	*set_path;
	t_cmd	*check;

	check = list->head;
	while (check)
	{
		i =  0;
		while (list->path[i])
		{
			set_path = ft_strjoin(list->path[i], "/");
			cmd = ft_strjoin(set_path, check->cmd[0]);
			free(set_path);
			if (access(cmd, X_OK) == 0)
				printf("The file exists.\n%s\n", cmd);
			// else
			// 	perror("access");
			i++;
		}
		check = check->next;
	}
}

int	strcmp_find_path(const char *path, const char *str)
{
	size_t	i;

	if (!path || !str)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((path[i] != str[i]) || !path[i])
			return (0);
		i++;
	}
	return (1);
}

char	**find_path(char **envp)
{
	int		i;
	char	*path;
	char	**path_split;

	i = 0;
	while (envp[i])
	{
		if (strcmp_find_path(envp[i], "PATH="))
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	path_split = ft_split(path, ':');
	free(path);
	return (path_split);
}

void	pipex_child(t_cmd_info *list, int cmd_i)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = list->head;
	while (i < cmd_i)
	{
		cmd = cmd->next;
		i++;
	}
	execve()
}

void	pipex_parent(t_cmd_info *list, pid_t *pid)
{
	int	i = 0;

	while (i < list->size)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	free();
}

int		main(int ac, char **av, char **envp)
{
	int			i;
	t_cmd_info	list;
	pid_t		*pid;

	if (ac != 5)
		return (0);
	list.in_file = av[1];
	list.in_file = av[ac - 1];
	list.size = ac -3;
	save_cmd(&list, av);
	list.path = find_path(envp);
	access_check(&list);
	pid = (pid_t *)malloc(sizeof(pid_t) * list.size);
	int i = 0;
	while (i < list.size)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			child(list, i);
		i++;
	}
	pipex_parent(&list, pid);







	// t_cmd	*new = list.head;
	// printf("%s\n", list.in_file);
	// printf("%s\n", list.out_file);
	// while (new)
	// {
	// 	printf("%s\n", new->cmd[0]);
	// 	printf("%s\n", new->cmd[1]);
	// 	new = new->next;
	// }
	// printf("%s\n", list.tail->cmd[0]);

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
