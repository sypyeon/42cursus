/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:45:50 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/20 14:04:11 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	strcount;

	strcount = 0;
	while (str[strcount] != '\0')
	{
		if ('A' <= str[strcount] && str[strcount] <= 'Z')
			str[strcount] = str[strcount] + 32;
		strcount++;
	}
	return (*&str);
}
