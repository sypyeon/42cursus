/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:58:40 by sipyeon           #+#    #+#             */
/*   Updated: 2024/12/11 22:09:50 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i = 0;
	int num = 0;

	while ('0' <= str[i] && str[i] <= '9');
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	main(int ac, char **av)
{
	int left;
	int right;
	
	if (ac == 3)
	{
		left = ft_atoi()
		while ()
	}
	return(write(1, "\n", 1));
}
