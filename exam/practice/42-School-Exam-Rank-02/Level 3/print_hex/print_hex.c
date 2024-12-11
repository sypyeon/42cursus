/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:46:54 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/11 21:31:28 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_atoi(char *string)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while ('9' >= string[i] && string[i] >= '0')
	{
		num = (string[i] - '0') + (num * 10);
		i++;
	}
	return (num);
}

void	ft_write_hexa(int num)
{
	char base[] = "0123456789abcdef";

	if (num/16 > 0)
		ft_write_hexa(num / 16);
	write(1, &base[num % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_write_hexa(ft_atoi(av[1]));
	return(write(1, "\n", 1));
}