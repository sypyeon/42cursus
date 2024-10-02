/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:01:51 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/24 02:28:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlen;
	unsigned int	srccount;
	unsigned int	srclen;

	srccount = 0;
	srclen = 0;
	destlen = 0;
	while (dest[destlen] != '\0')
		destlen++;
	while (src[srclen] != '\0')
		srclen++;
	if (destlen >= size)
		return (srclen + size);
	while (src[srccount] != '\0' && (destlen + srccount + 1) < size)
	{
		dest[destlen + srccount] = src[srccount];
		srccount++;
	}
	dest[destlen + srccount] = '\0';
	return (srclen + destlen);
}
