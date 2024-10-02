/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:13:49 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/22 13:45:39 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	strcount;

	strcount = 0;
	while (src[strcount] != '\0' || dest[strcount] != '\0')
	{
		dest[strcount] = src[strcount];
		strcount++;
		if (src[strcount] == '\0')
			dest[strcount] = src[strcount];
	}
	return (dest);
}
