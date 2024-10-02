/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:14:27 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/21 15:54:10 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	strcount;

	strcount = 0;
	while (str[strcount] != '\0')
	{
		if ('0' <= str[strcount] && str[strcount] <= '9')
			strcount++;
		else
			return (0);
	}
	return (1);
}
