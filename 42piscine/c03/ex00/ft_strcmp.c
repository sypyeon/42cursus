/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:03:49 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/23 22:43:54 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	strcount;

	strcount = 0;
	while ((s1[strcount] == s2[strcount]) && (s1[strcount] != '\0')
		&& (s2[strcount] != '\0'))
		strcount++;
	return (s1[strcount] - s2[strcount]);
}
