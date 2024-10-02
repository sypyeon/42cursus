/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:08:58 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/22 13:40:07 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	strlen;
	unsigned int	strcount;

	strlen = 0;
	strcount = 0;
	while (src[strlen] != '\0')
		strlen++;
	while (src[strcount] != '\0' && strcount + 1 < size)
	{
		dest[strcount] = src[strcount];
		strcount++;
	}
	dest[strcount] = '\0';
	return (strlen);
}
