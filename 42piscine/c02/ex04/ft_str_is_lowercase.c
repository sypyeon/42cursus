/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:22:43 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/21 15:54:22 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	strcount;

	strcount = 0;
	while (str[strcount] != '\0')
	{
		if ('a' <= str[strcount] && str[strcount] <= 'z')
			strcount++;
		else
			return (0);
	}
	return (1);
}
