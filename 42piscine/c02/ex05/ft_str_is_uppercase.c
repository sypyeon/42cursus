/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:36:52 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/20 11:49:27 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	strcount;

	strcount = 0;
	while (str[strcount] != '\0')
	{
		if ('A' <= str[strcount] && str[strcount] <= 'Z')
			strcount++;
		else
			return (0);
	}
	return (1);
}
