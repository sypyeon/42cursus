/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:40:41 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/25 21:52:47 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	destcount;
	unsigned int	srccount;

	destcount = 0;
	srccount = 0;
	while (dest[destcount] != '\0')
		destcount++;
	while ((src[srccount] != '\0') && (srccount < nb))
	{
		dest[destcount] = src[srccount];
		destcount++;
		srccount++;
	}
	dest[destcount] = '\0';
	return (dest);
}
