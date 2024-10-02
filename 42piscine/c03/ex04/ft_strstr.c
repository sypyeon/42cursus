/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:00:13 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/23 23:53:08 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	strcount;
	int	findcount;

	strcount = 0;
	if (to_find[strcount] == '\0')
		return (str);
	while (str[strcount] != '\0')
	{
		findcount = 0;
		if (str[strcount] == to_find[findcount])
		{
			while (to_find[findcount] != '\0'
				&& str[strcount + findcount] == to_find[findcount])
			{
				findcount++;
				if (to_find[findcount] == '\0')
					return (&str[strcount]);
			}
		}
		strcount++;
	}
	return (0);
}
