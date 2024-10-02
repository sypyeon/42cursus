/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:29:51 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/18 23:13:53 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	strcount;

	strcount = 0;
	while (str[strcount] != '\0')
	{
		if ('A' <= str[strcount] && str[strcount] <= 'Z')
			strcount++;
		else if (97 <= str[strcount] && str[strcount] <= 122)
			strcount++;
		else
			return (0);
	}
	return (1);
}
