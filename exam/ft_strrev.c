/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:10:27 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/28 20:12:18 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		last;
	char	temp;

	last = 0;
	while (str[last])
		last++;
	last--;
	i = 0;
	while (last > i)
	{
		temp = str[last];
		str[last] = str[i];
		str[i] = temp;
		i++;
		last--;
	}
	return (str);
}

#include <stdio.h>

int	main()
{
	char str[] = "HELLO WORLD!";
	printf("%s", ft_strrev(str));
	printf("%s", ft_strrev(str));
	return (0);
}