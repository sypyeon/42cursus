/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:17:33 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/25 22:08:06 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	strcount;

	strcount = 0;
	if (n == 0)
		return (0);
	while ((s1[strcount] == s2[strcount]) && (s1[strcount] != '\0')
		&& (s2[strcount] != '\0') && (strcount < n - 1))
		strcount++;
	return (s1[strcount] - s2[strcount]);
}
