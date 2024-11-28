/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:12:40 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/28 20:23:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	search_and_replace(char *string, char *v2, char *v3)
{
	int	i = 0;
	while (string[i])
	{
		if (string[i] == *v2)
			write(1, v3, 1);
		else
			write(1, &string[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 4 || ft_strlen(av[2]) != 1 || ft_strlen(av[3]) != 1)
		return (write(1, "\n", 1));
	search_and_replace(av[1], av[2], av[3]);
	return 0;
}
