/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:02:58 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/22 13:45:51 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	strcount;

	strcount = 0;
	while (strcount < n && src[strcount] != '\0')
	{
		dest[strcount] = src[strcount];
		strcount++;
	}
	while (strcount < n)
	{
		dest[strcount] = '\0';
		strcount++;
	}
	return (dest);
}
