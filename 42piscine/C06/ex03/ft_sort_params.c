/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 23:49:05 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/28 05:15:29 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort(char **str, int size)
{
	int		i;
	int		cmp;
	char	*temp;

	i = 1;
	while (i < size - 1)
	{
		cmp = i + 1;
		while (cmp < size)
		{
			if (ft_strcmp(str[i], str[cmp]) > 0)
			{
				temp = str[i];
				str[i] = str[cmp];
				str[cmp] = temp;
			}
			cmp++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	ft_sort(argv, argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
