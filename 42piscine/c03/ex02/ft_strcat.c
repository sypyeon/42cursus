/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:29:07 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/25 21:52:27 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	destcount;
	int	srccount;

	destcount = 0;
	srccount = 0;
	while (dest[destcount] != '\0')
		destcount++;
	while (src[srccount] != '\0')
	{
		dest[destcount] = src[srccount];
		destcount++;
		srccount++;
	}
	dest[destcount] = '\0';
	return (dest);
}
