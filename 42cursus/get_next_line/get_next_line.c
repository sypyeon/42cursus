/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:37:35 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/05 19:13:27 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char *buf, char *save_line)
{
	int		n;
	char	*tmp;

	n = 1;
	while (!(ft_strchr(save_line, '\n')) || n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		buf[n] = '\0';
		tmp = save_line;
		save_line = ft_str_join(save_line, buf);
		free(tmp);
		if (!save_line)
			return (-1);
	}
	return (n);
}

char	*get_line(int fd, char *buf, char *save_line)
{
	int	n;

	n = read_file(fd, buf, save_line);
	if (n == -1 || !save_line)
		return (NULL);
	if (n == 0)
		return ()
	
	
}

char	*get_next_line(int fd)
{
	static char	*save_line;
	char		*buf;
	char		*read_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_line = get_line(fd, buf, save_line);
	
	return (read_line);
}
